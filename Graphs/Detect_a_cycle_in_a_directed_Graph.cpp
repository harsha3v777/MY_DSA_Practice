#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool DFS(int node, vector<int>& vis, vector<int> adj[], vector<int>& pathvis) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (DFS(it, vis, adj, pathvis)) return true;
            }
            else if (pathvis[it] == 1) {
                return true; // back edge found -> cycle
            }
        }

        pathvis[node] = 0; // remove from recursion stack
        return false;
    }

public:
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> vis(N, 0);
        vector<int> pathvis(N, 0);

        for (int i = 0; i < N; i++) {
            if (vis[i] == 0) {
                if (DFS(i, vis, adj, pathvis)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // Example graph
    int N = 4;
    vector<int> adj[N];

    // Graph edges (Directed)
    // 0 -> 1 -> 2 -> 0 forms a cycle
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);

    // Add another edge (no cycle here)
    adj[2].push_back(3);

    Solution obj;
    bool hasCycle = obj.isCyclic(N, adj);

    if (hasCycle) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
