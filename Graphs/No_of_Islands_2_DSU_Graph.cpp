#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A) {
        int k = A.size();
        vector<int> ans;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        DisjointSet ds(n*m);
        int cnt = 0;

        int delRow[4] = {0, 1, 0, -1};
        int delCol[4] = {1, 0, -1, 0};

        for (int i = 0; i < k; i++) {
            int row = A[i][0];
            int col = A[i][1];

            if (grid[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }

            grid[row][col] = 1;
            cnt++;
            int node = row * m + col;

            for (int l = 0; l < 4; l++) {
                int nrow = row + delRow[l];
                int ncol = col + delCol[l];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                    int nbr = nrow * m + ncol;
                    if (ds.findUPar(node) != ds.findUPar(nbr)) {
                        ds.UnionByRank(node, nbr);
                        cnt--;
                    }
                }
            }

            ans.push_back(cnt);
        }
        return ans;
    }
};

//Time Complexity: O(k)
//Space Complexity: O(n·m)

int main() {
    // Example Input (hardcoded, no user input needed)
    int n = 4, m = 5;
    vector<vector<int>> A = {{1,1},{0,1},{3,3},{3,4}};

    Solution sol;
    vector<int> result = sol.numOfIslands(n, m, A);

    // Print output
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
