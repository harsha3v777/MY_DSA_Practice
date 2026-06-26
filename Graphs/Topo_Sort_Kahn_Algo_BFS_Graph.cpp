#include <bits/stdc++.h>
using namespace std;

//only possible for directed acyclic graphs

class Solution {
private:
    void BFS(int V, vector<int> adj[], queue<int> &q,
             vector<int> &indegree, vector<int> &ans) {
        // Push all nodes with indegree 0 into queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // Reduce indegree of all neighbors
            for (auto nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> indegree(V, 0);
        vector<int> ans;

        // Step 1: Compute indegree
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Step 2: Run BFS
        BFS(V, adj, q, indegree, ans);

        // Step 3: Detect cycle (if topo sort is incomplete)
        if (ans.size() < V) {
            cout << "Graph contains a cycle! No valid Topological Sort.\n";
            return {};
        }

        return ans;
    }
};

//O(e+v) - t.c

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter edges (u v) meaning u -> v:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    vector<int> topo = obj.topoSort(V, adj);

    if (!topo.empty()) {
        cout << "Topological Sort Order: ";
        for (int node : topo) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
