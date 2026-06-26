//Topological Sort Algorithm directed graph
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void DFS(int node, vector<int>& vis, stack<int>& s, vector<int> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                DFS(it, vis, s, adj);
            }
        }
        s.push(node);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        stack<int> s;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                DFS(i, vis, s, adj);
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

//O(v+e) - t.c

int main() {
    int V = 6;
    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> result = obj.topoSort(V, adj);

    cout << "Topological Sort: ";
    for (auto x : result) cout << x << " ";
    cout << endl;

    return 0;
}
