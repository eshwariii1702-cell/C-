
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Edge {
    int u, v, weight;
};

class Graph {
private:
    int V;
    vector<pair<int, int>> adjList[20];
    vector<Edge> edges;
    int parent[20], rankArr[20];

public:
    Graph(int vertices) {
        V = vertices;

        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rankArr[i] = 0;
        }
    }

    void addEdge(int u, int v, int weight) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
            edges.push_back({u, v, weight});
        }
    }

    void displayList() {
        cout << "\n--- Weighted Adjacency List ---" << endl;

        for (int i = 0; i < V; i++) {
            cout << i << ": ";

            for (auto edge : adjList[i]) {
                cout << edge.first << "(w:"
                     << edge.second << ") -> ";
            }

            cout << endl;
        }
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);

        return parent[i];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rankArr[rootX] < rankArr[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rankArr[rootX] > rankArr[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rankArr[rootX]++;
        }
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end(),
             [](Edge a, Edge b) {
                 return a.weight < b.weight;
             });

        vector<Edge> mst;
        int totalCost = 0;

        for (auto edge : edges) {
            int rootU = find(edge.u);
            int rootV = find(edge.v);

            if (rootU != rootV) {
                mst.push_back(edge);
                totalCost += edge.weight;
                unite(rootU, rootV);
            }
        }

        cout << "\n--- Minimum Spanning Tree (Kruskal's) ---"
             << endl;

        for (auto edge : mst) {
            cout << edge.u << " -- " << edge.v
                 << " == " << edge.weight << endl;
        }

        cout << "Total Minimum Cost: " << totalCost << endl;

        if (mst.size() != V - 1)
            cout << "Graph is disconnected. MST does not exist." << endl;
    }
};

int main() {
    int v, e, u, w, weight;

    cout << "Enter number of vertices: ";
    cin >> v;

    if (v <= 0 || v > 20) {
        cout << "Invalid number of vertices." << endl;
        return 0;
    }

    cout << "Enter number of edges: ";
    cin >> e;

    Graph g(v);

    cout << "Enter edges (u v weight) using 0-based indexing:"
         << endl;

    for (int i = 0; i < e; i++) {
        cin >> u >> w >> weight;
        g.addEdge(u, w, weight);
    }

    g.displayList();
    g.kruskalMST();

    return 0;
}
