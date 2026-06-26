#include <bits/stdc++.h>
using namespace std;

class Solution {

public:

    /* Tabulation (2D DP)
       Time:  O(n^2)
       Space: O(n^2)
    */
    int rodCuttingTabulation(vector<int> &price, int n) {
        int s = price.size();
        vector<vector<int>> dp(s, vector<int>(n + 1, 0));

        for (int len = 0; len <= n; len++)
            dp[0][len] = len * price[0];

        for (int idx = 1; idx < s; idx++) {
            int rodLen = idx + 1;
            for (int len = 0; len <= n; len++) {
                int notPick = dp[idx - 1][len];
                int pick = (len >= rodLen) ? price[idx] + dp[idx][len - rodLen] : INT_MIN;
                dp[idx][len] = max(pick, notPick);
            }
        }
        return dp[s - 1][n];
    }

    /* Space Optimized (1D DP)
       Time:  O(n^2)
       Space: O(n)
    */
    int rodCuttingSpaceOptimized(vector<int> &price, int n) {
        int s = price.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int len = 0; len <= n; len++)
            prev[len] = len * price[0];

        for (int idx = 1; idx < s; idx++) {
            int rodLen = idx + 1;
            for (int len = 0; len <= n; len++) {
                int notPick = prev[len];
                int pick = (len >= rodLen) ? price[idx] + curr[len - rodLen] : INT_MIN;
                curr[len] = max(pick, notPick);
            }
            prev = curr;
        }
        return prev[n];
    }
};

int main() {

    vector<int> price = {1, 6, 8, 9, 10, 19, 7, 20};
    int n = 8;

    Solution sol;

    cout << sol.rodCuttingTabulation(price, n) << "\n";
    cout << sol.rodCuttingSpaceOptimized(price, n) << "\n";

    return 0;
}
