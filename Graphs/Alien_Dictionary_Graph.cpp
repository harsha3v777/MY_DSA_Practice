#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];

        // Step 1: Build graph
        for (int i = 0; i < N - 1; i++) {
            string str1 = dict[i];
            string str2 = dict[i + 1];
            int len = min(str1.size(), str2.size());

            for (int j = 0; j < len; j++) {
                if (str1[j] != str2[j]) {
                    adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                    break; // only first different character matters
                }
            }
        }

        // Step 2: Compute indegree
        vector<int> indegree(K, 0);
        for (int i = 0; i < K; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Step 3: Kahn’s Algorithm (BFS Topo Sort)
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) q.push(nbr);
            }
        }

        // Step 4: Convert topo order to string
        string ans = "";
        for (auto it : topo) {
            ans += (char)(it + 'a');
        }

        return ans;
    }
};

int main() {
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    Solution obj;
    string order = obj.findOrder(dict, N, K);

    cout << "Alien Dictionary Order: " << order << endl;

    return 0;
}
