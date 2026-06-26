#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^3)
// Space Complexity: O(N^2)

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int i, int j, bool isTrue,
              string s,
              vector<vector<vector<int>>> &dp) {

        if (i > j) return 0;

        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        long long ways = 0;

        for (int k = i + 1; k <= j - 1; k += 2) {

            long long lt = solve(i, k - 1, true, s, dp);
            long long lf = solve(i, k - 1, false, s, dp);
            long long rt = solve(k + 1, j, true, s, dp);
            long long rf = solve(k + 1, j, false, s, dp);

            if (s[k] == '&') {

                if (isTrue) {
                    ways = (ways + (lt * rt) % MOD) % MOD;
                } else {
                    ways = (ways + (lt * rf) % MOD
                                  + (lf * rt) % MOD
                                  + (lf * rf) % MOD) % MOD;
                }

            }
            else if (s[k] == '|') {

                if (isTrue) {
                    ways = (ways + (lt * rt) % MOD
                                  + (lt * rf) % MOD
                                  + (lf * rt) % MOD) % MOD;
                } else {
                    ways = (ways + (lf * rf) % MOD) % MOD;
                }

            }
            else if (s[k] == '^') {

                if (isTrue) {
                    ways = (ways + (lt * rf) % MOD
                                  + (lf * rt) % MOD) % MOD;
                } else {
                    ways = (ways + (lt * rt) % MOD
                                  + (lf * rf) % MOD) % MOD;
                }
            }
        }

        return dp[i][j][isTrue] = ways;
    }

    int countTrue(string s) {

        int n = s.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n, vector<int>(2, -1))
        );

        return solve(0, n - 1, true, s, dp);
    }
};

int main() {

    Solution obj;

    string expr1 = "T|T&F^T";
    cout << "Expression: " << expr1 << endl;
    cout << "Ways to evaluate TRUE: "
         << obj.countTrue(expr1) << endl;

    cout << endl;

    string expr2 = "T^F|F";
    cout << "Expression: " << expr2 << endl;
    cout << "Ways to evaluate True: "
         << obj.countTrue(expr2) << endl;

    return 0;
}