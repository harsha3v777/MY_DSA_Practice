#include <bits/stdc++.h>
using namespace std;

//O(Elog(E))

class Solution {
public:
    int spanningTree(int V, vector<vector<pair<int,int>>>& adj) {
        // Min-Heap {wt, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(V, 0);
        int minWeight = 0;

        // Start with node 0
        pq.push({0, 0});

        while (!pq.empty()) {
            pair<int,int> top = pq.top();
            pq.pop();

            int wt = top.first;
            int node = top.second;

            if (vis[node]) continue;
            vis[node] = 1;
            minWeight += wt;

            for (auto &nbr : adj[node]) {
                int nextNode = nbr.first;
                int edgeWt  = nbr.second;
                if (!vis[nextNode]) {
                    pq.push({edgeWt, nextNode});
                }
            }
        }
        return minWeight;
    }
};

int main() {
    int V = 4;
    vector<vector<pair<int,int>>> adj(V);

    // Build graph (undirected)
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});

    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});

    adj[2].push_back({3, 3});
    adj[3].push_back({2, 3});

    adj[0].push_back({3, 4});
    adj[3].push_back({0, 4});

    Solution sol;
    cout << "MST Weight = " << sol.spanningTree(V, adj) << endl;

    return 0;
}
