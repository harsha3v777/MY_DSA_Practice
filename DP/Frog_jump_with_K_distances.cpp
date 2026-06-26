#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 🐢 1️⃣ Recursive version (no DP)
    // t.c - O(K^N) , s.c - O(N) + O(N)
    int JumpRec(int idx, vector<int>& heights, int k) {
        if (idx == 0) return 0;
        int minSteps = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (idx >= j) {
                int cost = JumpRec(idx - j, heights, k) + abs(heights[idx] - heights[idx - j]);
                minSteps = min(minSteps, cost);
            }
        }

        return minSteps;
    }

    // ⚡ 2️⃣ Memoized version (with DP)
    // t.c - O(K*N) , s.c - O(N)
    int JumpMemo(int idx, vector<int>& heights, int k, vector<int>& dp) {
        if (idx == 0) return 0;
        if (dp[idx] != -1) return dp[idx];

        int minSteps = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (idx >= j) {
                int cost = JumpMemo(idx - j, heights, k, dp) + abs(heights[idx] - heights[idx - j]);
                minSteps = min(minSteps, cost);
            }
        }

        return dp[idx] = minSteps;
    }

public:
    // Call without DP
    int frogJumpRecursive(vector<int>& heights, int k) {
        int n = heights.size();
        return JumpRec(n - 1, heights, k);
    }

    // Call with DP (memoization)
    int frogJumpDP(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return JumpMemo(n - 1, heights, k, dp);
    }
};

int main() {
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int k = 2;

    Solution sol;

    cout << "🐢 Without DP (Pure Recursion): "
         << sol.frogJumpRecursive(heights, k) << endl;

    cout << "⚡ With DP (Memoization): "
         << sol.frogJumpDP(heights, k) << endl;

    return 0;
}
