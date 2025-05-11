#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef pair<int, int> p; // (weight, node)

public:
    int spanningTree(int v, vector<vector<int>> adj[]) {
        priority_queue<p, vector<p>, greater<p>> pq; // Min-heap (weight, node)
        vector<int> key(v, INT_MAX);     // Key values used to pick minimum weight edge
        vector<bool> inMst(v, false);    // To represent set of vertices not yet included in MST
        vector<int> parent(v, -1);       // Store MST edges

        key[0] = 0;
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            if (inMst[node])
                continue;

            inMst[node] = true;
            sum += key[node];

            for (auto &vec : adj[node]) {
                int adjNode = vec[0];
                int wt = vec[1];

                if (!inMst[adjNode] && wt < key[adjNode]) {
                    key[adjNode] = wt;
                    pq.push({wt, adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        cout << "Minimum Spanning Tree Edges:\n";
        for (int i = 1; i < v; i++) {
            cout << "Edge: " << parent[i] << " - " << i
                 << " (Weight: " << key[i] << ")\n";
        }

        return sum;
    }
};

int main() {
    int v = 6;
    vector<vector<int>> adj[v];

    // Undirected graph: add both directions
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});

    adj[0].push_back({4, 3});
    adj[4].push_back({0, 3});

    adj[1].push_back({4, 1});
    adj[4].push_back({1, 1});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[4].push_back({5, 4});
    adj[5].push_back({4, 4});

    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});

    adj[2].push_back({5, 1});
    adj[5].push_back({2, 1});

    adj[4].push_back({3, 5});
    adj[3].push_back({4, 5});

    Solution obj;
    int sum = obj.spanningTree(v, adj);

    cout << "Total Weight of MST: " << sum << endl;

    return 0;
}
