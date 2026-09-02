#include <iostream>
#include <queue>
using namespace std;

class Graph
{
    int adj[20][20];
    int n;
    bool visited[20] = {false};

public:

    // Create Graph
    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> n;

        // Initialize adjacency matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }

        int edges;
        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (source destination):\n";

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        cout << "Graph created successfully.\n";
    }

    // Display Adjacency Matrix
    void displayMatrix()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Reset visited array
    void resetVisited()
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
    }

    // DFS Traversal
    void DFS(int start)
    {
        visited[start] = true;

        cout << start << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[start][i] == 1 && !visited[i])
            {
                DFS(i);
            }
        }
    }

    // BFS Traversal
    void BFS(int start)
    {
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int i = 0; i < n; i++)
            {
                if (adj[current][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    int choice, start;

    do
    {
        cout << "\n========== GRAPH MENU ==========";
        cout << "\n1. Create Graph";
        cout << "\n2. Display Graph (Adjacency Matrix)";
        cout << "\n3. DFS Traversal";
        cout << "\n4. BFS Traversal";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.createGraph();
            break;

        case 2:
            g.displayMatrix();
            break;

        case 3:
            g.resetVisited();

            cout << "Enter starting vertex: ";
            cin >> start;

            cout << "DFS Traversal: ";
            g.DFS(start);
            cout << endl;
            break;

        case 4:
            g.resetVisited();

            cout << "Enter starting vertex: ";
            cin >> start;

            cout << "BFS Traversal: ";
            g.BFS(start);
            cout << endl;
            break;

        case 5:
            cout << "Program Exited.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
