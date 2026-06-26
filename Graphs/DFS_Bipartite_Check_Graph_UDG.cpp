#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<int> adj[]) {
        color[node] = col; // assign color

        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (!dfs(it, !col, color, adj)) return false;
            }
            else if (color[it] == col) {
                return false; // same color as parent -> not bipartite
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1); // -1 means uncolored

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, adj)) return false;
            }
        }
        return true;
    }
};

int main() {
    int V = 4;
    vector<int> adj[V];

    // Example graph: Bipartite
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    Solution obj;
    bool ans = obj.isBipartite(V, adj);

    if (ans) cout << "Graph is Bipartite\n";
    else cout << "Graph is NOT Bipartite\n";

    return 0;
}
