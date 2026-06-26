#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Min-heap {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        vector<int> dist(V, 1e9);
        dist[S] = 0;
        minHeap.push({0, S});  // {dist, node}

        while (!minHeap.empty()) {
            int length = minHeap.top().first;
            int node   = minHeap.top().second;
            minHeap.pop();

            if (length > dist[node]) continue;

            for (auto it : adj[node]) {
                int v  = it[0];
                int wt = it[1];
                if (dist[v] > dist[node] + wt) {
                    dist[v] = dist[node] + wt;
                    minHeap.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

int main() {
    int V = 5;  // number of vertices
    int E = 6;  // number of edges

    vector<vector<int>> adj[V];

    // edges: {u, v, w}
    vector<tuple<int,int,int>> edges = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, 5},
        {1, 3, 10},
        {2, 4, 3},
        {3, 4, 4}
    };

    // build adjacency list
    for (auto edge : edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int w = get<2>(edge);

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed graph
    }

    int S = 0; // source vertex

    Solution obj;
    vector<int> dist = obj.dijkstra(V, adj, S);

    cout << "Shortest distances from source " << S << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << dist[i] << "\n";
    }

    return 0;
}
