#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void DFS(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &s) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int neigh = it.first;
            if (!vis[neigh]) {
                DFS(neigh, adj, vis, s);
            }
        }
        s.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        vector<pair<int,int>> adj[N];
        for (int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        vector<int> vis(N, 0);
        stack<int> s;

        // Topological Sort
        //O(N+M)-t.c
        for (int j = 0; j < N; j++) {
            if (!vis[j]) {
                DFS(j, adj, vis, s);
            }
        }

        // Distance array
        vector<int> dist(N, 1e9);
        dist[0] = 0; // assuming source = 0

        // Relax edges in topo order
        //O(N+M)
        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (dist[node] != 1e9) {
                for (auto it : adj[node]) {
                    int nbr = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[nbr]) {
                        dist[nbr] = dist[node] + wt;
                    }
                }
            }
        }

        // Replace INF with -1
        for (int j = 0; j < N; j++) {
            if (dist[j] == 1e9) {
                dist[j] = -1;
            }
        }

        return dist;
    }
};

int main() {
    // Inbuilt graph input
    int N = 6, M = 7;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {4, 5, 4},
        {2, 3, 6},
        {5, 3, 1}
    };

    Solution sol;
    vector<int> ans = sol.shortestPath(N, M, edges);

    cout << "Shortest distances from node 0:\n";
    for (int d : ans) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
