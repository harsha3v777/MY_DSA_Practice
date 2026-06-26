#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void Kahn(int N, vector<int> adj[], vector<int> &indegree,
              vector<int> &ans, queue<int> &q) {
        
        // Push all nodes with indegree = 0
        for (int j = 0; j < N; j++) {
            if (indegree[j] == 0) {
                q.push(j);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

public:
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> indegree(N, 0);
        vector<int> ans;
        queue<int> q;

        // Step 1: Build indegree array
        for (int i = 0; i < N; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Step 2: Perform Kahn’s algorithm
        Kahn(N, adj, indegree, ans, q);

        // Step 3: If topo sort includes all nodes → no cycle
        if (ans.size() == N) {
            return false; // no cycle
        }
        return true; // cycle exists
    }
};

int main() {
    int N = 4; // number of nodes
    vector<int> adj[4];

    // Example 1: Graph with a cycle
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0); // cycle here (0->1->2->0)
    adj[2].push_back(3);

    Solution sol;
    cout<<"SOl 1 : "<<endl;
    if (sol.isCyclic(N, adj)) {
        cout << "Graph has a cycle " << endl;
    } else {
        cout << "Graph has no cycle " << endl;
    }

    // Example 2: Graph without a cycle
    vector<int> adj2[4];
    adj2[0].push_back(1);
    adj2[1].push_back(2);
    adj2[2].push_back(3);

    cout<<"SOl 2 : "<<endl;
    if (sol.isCyclic(N, adj2)) {
        cout << "Graph has a cycle " << endl;
    } else {
        cout << "Graph has no cycle " << endl;
    }

    return 0;
}
