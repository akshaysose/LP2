#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add undirected edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Because undirected
    }

    // Recursive DFS Helper
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // DFS Traversal (All Components)
    void DFS() {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
        cout << endl;
    }

    // BFS Traversal (All Components)
    void BFS() {
        vector<bool> visited(V, false);
        queue<int> q;

        cout << "BFS Traversal: ";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    cout << curr << " ";

                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        cout << endl;
    }
};

// ---------- MAIN ----------
int main() {
    Graph g(6); // Create a graph with 6 vertices (0 to 5)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.DFS(); // Recursive
    g.BFS(); // Iterative

    return 0;
}
