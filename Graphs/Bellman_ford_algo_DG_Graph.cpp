#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        const int INF = 1e9;
        int n = edges.size();
        vector<int> dist(V, INF);
        dist[S] = 0;

        // Relax edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (int j = 0; j < n; j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                if (dist[u] != INF && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Detect negative cycle
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                return {-1}; // Negative cycle found
            }
        }

        return dist;
    }
};

int main() {
    // Hardcoded input
    int V = 5; // number of vertices
    int E = 8; // number of edges
    int S = 0; // source vertex

    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    Solution sol;
    vector<int> dist = sol.bellman_ford(V, edges, S);

    if (dist.size() == 1 && dist[0] == -1) {
        cout << "Graph contains a negative weight cycle." << endl;
    } else {
        cout << "Shortest distances from source " << S << ":" << endl;
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9)
                cout << "Vertex " << i << " : INF" << endl;
            else
                cout << "Vertex " << i << " : " << dist[i] << endl;
        }
    }

    return 0;
}
