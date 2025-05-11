#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the shortest distance of all the vertices from the source vertex
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int source) {
        // Min-heap to store {distance, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);  // Initialize distances with infinity

        result[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &vec : adj[node]) {
                int adjNode = vec[0];
                int wt = vec[1];

                if (d + wt < result[adjNode]) {
                    result[adjNode] = d + wt;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }

        return result;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj[V];

    // Constructing the graph: each adj[u] contains {v, weight}
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[2].push_back({3, 6});
    adj[4].push_back({2, 2});
    adj[4].push_back({3, 4});

    int source = 0;

    Solution obj;
    vector<int> dist = obj.dijkstra(V, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << dist[i] << "\n";
    }

    return 0;
}
