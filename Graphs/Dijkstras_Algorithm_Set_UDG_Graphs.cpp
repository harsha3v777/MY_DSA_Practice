#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int,int>> st; // {dist, node}
        vector<int> dist(V, 1e9);

        dist[S] = 0;
        st.insert({0, S}); // {distance, node}

        while (!st.empty()) {
            auto it = *(st.begin());
            int wt   = it.first;   // current distance
            int node = it.second;  // current node
            st.erase(it);

            for (auto edge : adj[node]) {
                int adjNode = edge[0];
                int edW     = edge[1];

                if (dist[adjNode] > dist[node] + edW) {
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dist[node] + edW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main() {
    int V = 5; // number of vertices
    int E = 6; // number of edges
    vector<vector<int>> adj[V];

    // Example Graph (undirected)
    vector<tuple<int,int,int>> edges = {
        make_tuple(0,1,2), make_tuple(0,2,4), make_tuple(1,2,1),
        make_tuple(1,3,7), make_tuple(2,4,3), make_tuple(3,4,1)
    };

    for (auto edge : edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int w = get<2>(edge);

        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // remove this line if graph is directed
    }

    int S = 0; // source node
    Solution sol;
    vector<int> dist = sol.dijkstra(V, adj, S);

    cout << "Shortest distances from source " << S << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << dist[i] << "\n";
    }

    return 0;
}

