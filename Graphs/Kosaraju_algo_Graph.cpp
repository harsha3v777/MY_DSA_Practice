#include <bits/stdc++.h>
using namespace std;

//Your task is to find the number of strongly connected components (SCCs) in the graph.

class Solution {
private:
    void DFS(stack<int>& s, vector<int> adj[], int node, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                DFS(s, adj, it, vis);
            }
        }
        s.push(node);
    }

    void revDFS(vector<int> reverseAdj[], int ele, vector<int>& revVis) {
        revVis[ele] = 1;
        for (auto it : reverseAdj[ele]) {
            if (revVis[it] == 0) {
                revDFS(reverseAdj, it, revVis);
            }
        }
    }

public:
    int kosaraju(int V, vector<int> adj[]) {
        stack<int> s;
        vector<int> vis(V, 0);

        // Step 1: Fill stack with finish time order
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                DFS(s, adj, i, vis);
            }
        }

        // Step 2: Reverse the graph
        vector<int> reverseAdj[V];
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                reverseAdj[it].push_back(i);
            }
        }

        // Step 3: Process nodes in stack order
        vector<int> revVis(V, 0);
        int cnt = 0;
        while (!s.empty()) {
            int ele = s.top();
            s.pop();

            if (revVis[ele] == 0) {
                cnt++;
                revDFS(reverseAdj, ele, revVis);
            }
        }

        return cnt;
    }
};

// t.c,s.c -> O(E+V)

int main() {
    int V = 5;
    vector<int> adj[V];

    // Example Directed Graph
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);

    Solution sol;
    int numSCC = sol.kosaraju(V, adj);

    cout << "Number of Strongly Connected Components: " << numSCC << endl;

    return 0;
}
