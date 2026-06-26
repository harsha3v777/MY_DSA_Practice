#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M) {
        vector<int> adj[N];

        // Build adjacency list
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS
        queue<int> q;
        vector<int> dis(N, 1e9); // initially "infinity"
        dis[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nbr : adj[node]) {
                if (dis[node] + 1 < dis[nbr]) {
                    dis[nbr] = dis[node] + 1;
                    q.push(nbr);
                }
            }
        }

        // Replace infinity with -1
        for (int k = 0; k < N; k++) {
            if (dis[k] == (int)1e9) {
                dis[k] = -1;
            }
        }

        return dis;
    }
};

int main() {
    // Inbuilt input
    int N = 6, M = 7; 
    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,3}, {2,3}, {2,4}, {3,5}, {4,5}
    };

    Solution obj;
    vector<int> ans = obj.shortestPath(edges, N, M);

    cout << "Shortest distances from node 0:\n";
    for (int d : ans) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}


