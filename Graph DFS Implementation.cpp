
#include <iostream>
using namespace std;

class Graph {
private:
    int V;
    int adjMatrix[20][20];

public:
    Graph(int vertices) {
        V = vertices;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

    void displayMatrix() {
        cout << "\n--- Adjacency Matrix ---" << endl;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int startVertex, bool visited[]) {
        visited[startVertex] = true;
        cout << startVertex << " ";

        for (int neighbor = 0; neighbor < V; neighbor++) {
            if (adjMatrix[startVertex][neighbor] == 1 &&
                !visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }

    void startDFS(int startVertex) {
        bool visited[20] = {false};

        cout << "DFS Traversal: ";
        DFS(startVertex, visited);
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

    g.displayMatrix();

    int start;

    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;

    if (start >= 0 && start < v) {
        g.startDFS(start);
    } else {
        cout << "Invalid starting vertex." << endl;
    }

    return 0;
}
