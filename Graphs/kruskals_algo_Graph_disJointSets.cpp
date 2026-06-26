#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (DSU) with Union by Rank + Path Compression
class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    void UnionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

// Solution class for Kruskal’s MST
class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;

        // Step 1: Collect all edges
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                edges.push_back({wt, {i, adjNode}});
            }
        }

        // Step 2: Sort edges by weight
        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int mstWt = 0;

        // Step 3: Kruskal’s Algorithm
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.UnionByRank(u, v);
            }
        }

        return mstWt;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    int V = 5;  // number of vertices
    vector<vector<int>> adj[5];

    // Graph edges: u - v with weight w
    // 0-1 (2), 0-3 (6), 1-2 (3), 1-3 (8), 1-4 (5), 2-4 (7), 3-4 (9)

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});

    Solution obj;
    cout << "MST Weight = " << obj.spanningTree(V, adj) << endl;

    return 0;
}
