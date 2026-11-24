
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    vector<int> adjList[20];

public:
    Graph(int vertices) {
        V = vertices;
    }

    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void displayList() {
        cout << "\n--- Adjacency List ---" << endl;

        for (int i = 0; i < V; i++) {
            cout << i << ": ";

            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j];

                if (j != adjList[i].size() - 1)
                    cout << " -> ";
            }

            cout << endl;
        }
    }

    void BFS(int startVertex) {
        bool visited[20] = {false};
        queue<int> q;

        q.push(startVertex);
        visited[startVertex] = true;

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    int v, e, u, w;

    cout << "Enter number of vertices: ";
    cin >> v;

    if (v <= 0 || v > 20) {
        cout << "Invalid number of vertices." << endl;
        return 0;
    }

    cout << "Enter number of edges: ";
    cin >> e;

    Graph g(v);

    cout << "Enter edges (u v) using 0-based indexing:" << endl;

    for (int i = 0; i < e; i++) {
        cin >> u >> w;
        g.addEdge(u, w);
    }

    g.displayList();

    int start;

    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;

    if (start >= 0 && start < v)
        g.BFS(start);
    else
        cout << "Invalid starting vertex." << endl;

    return 0;
}
