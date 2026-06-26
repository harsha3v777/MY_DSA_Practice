#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int timer = 1;

    void DFS(int node, int parent, vector<int> adj[], vector<int> &vis, int tin[], int low[], vector<int> &mark) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (vis[it] == 0) {
                DFS(it, node, adj, vis, tin, low, mark);
                low[node] = min(low[node], low[it]);

                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }

        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                DFS(i, -1, adj, vis, tin, low, mark);
            }
        }

        vector<int> ans;
        for (int j = 0; j < n; j++) {
            if (mark[j] == 1) {
                ans.push_back(j);
            }
        }

        return ans;
    }
};

int main() {
    int n = 5;
    vector<int> adj[n];

    // Example Graph
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution sol;
    vector<int> articulationPts = sol.articulationPoints(n, adj);

    cout << "Articulation Points: ";
    for (int pt : articulationPts) {
        cout << pt << " ";
    }
    cout << endl;

    return 0;
}
