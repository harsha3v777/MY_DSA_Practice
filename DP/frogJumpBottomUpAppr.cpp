#include <bits/stdc++.h>
using namespace std;

// BOTTOM UP Apporach

class Solution {
public:
    // ✅ Approach 1: Tabulation (DP Array)
    int frogJumpTabulation(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, 0);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]); // one step
            int ss = INT_MAX;
            if (i > 1) {
                ss = dp[i - 2] + abs(heights[i] - heights[i - 2]); // two steps
            }
            dp[i] = min(fs, ss);
        }
        return dp[n - 1];
    }

    // ✅ Approach 2: Space Optimized (O(1) Space)
    int frogJumpSpaceOptimized(vector<int>& heights) {
        int n = heights.size();
        int prev1 = 0; // dp[i-1]
        int prev2 = 0; // dp[i-2]

        for (int i = 1; i < n; i++) {
            int fs = prev1 + abs(heights[i] - heights[i - 1]); // one step
            int ss = INT_MAX;
            if (i > 1) {
                ss = prev2 + abs(heights[i] - heights[i - 2]); // two steps
            }
            int curr = min(fs, ss);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;

    vector<int> heights1 = {2, 1, 3, 5, 4};
    vector<int> heights2 = {7, 5, 1, 2, 6};

    cout << "Tabulation Result 1: " << sol.frogJumpTabulation(heights1) << endl;
    cout << "Space Optimized Result 1: " << sol.frogJumpSpaceOptimized(heights1) << endl;

    cout << "Tabulation Result 2: " << sol.frogJumpTabulation(heights2) << endl;
    cout << "Space Optimized Result 2: " << sol.frogJumpSpaceOptimized(heights2) << endl;

    return 0;
}
