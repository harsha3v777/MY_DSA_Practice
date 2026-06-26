#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS helper
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ls);
            }
        }
    }

    // DFS main function
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};  // visited array
        vector<int> ls;    // result list
        dfs(0, adj, vis, ls); // start DFS from node 0
        return ls;
    }

    // BFS function
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};  // visited array
        queue<int> q;
        vector<int> bfs;   // result list

        q.push(0);         // start BFS from node 0
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment this line if graph is directed
    }

    Solution obj;

    vector<int> dfsResult = obj.dfsOfGraph(V, adj);
    vector<int> bfsResult = obj.bfsOfGraph(V, adj);

    cout << "\nDFS Traversal: ";
    for (int node : dfsResult) {
        cout << node << " ";
    }

    cout << "\nBFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }

    cout << endl;
    return 0;
}
