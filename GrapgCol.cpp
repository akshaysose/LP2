#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GraphColoring {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<int> colors; // Colors assigned to each vertex
    int minColorsUsed;

    bool isSafe(int node, int color) {
        for (int neighbor : adj[node]) {
            if (colors[neighbor] == color)
                return false;
        }
        return true;
    }

    // Branch and Bound + Backtracking
    void solve(int node, int maxColorUsed) {
        if (node == V) {
            minColorsUsed = min(minColorsUsed, maxColorUsed);
            return;
        }

        for (int color = 1; color <= minColorsUsed; color++) {
            if (isSafe(node, color)) {
                colors[node] = color;
                solve(node + 1, max(maxColorUsed, color));
                colors[node] = 0; // Backtrack
            }
        }
    }

    // Print one valid coloring
    bool solveAndPrint(int node) {
        if (node == V) {
            for (int i = 0; i < V; i++) {
                cout << "Vertex " << i << " ---> Color " << colors[i] << endl;
            }
            return true;
        }

        for (int color = 1; color <= minColorsUsed; color++) {
            if (isSafe(node, color)) {
                colors[node] = color;
                if (solveAndPrint(node + 1))
                    return true;
                colors[node] = 0;
            }
        }
        return false;
    }

public:
    GraphColoring(int vertices, vector<vector<int>> adjList)
        : V(vertices), adj(adjList), colors(vertices, 0), minColorsUsed(vertices) {}

    void findMinimumColors() {
        solve(0, 0);
        cout << "Minimum number of colors needed: " << minColorsUsed << endl;
        cout << "One valid coloring is:\n";
        solveAndPrint(0);
    }
};

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    // Graph (Adjacency List) - undirected
    adj[0] = {1, 2, 3};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {0, 2};

    GraphColoring gc(V, adj);
    gc.findMinimumColors();

    return 0;
}
