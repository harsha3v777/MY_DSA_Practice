#include <bits/stdc++.h>
using namespace std;

/*
    Unbounded Knapsack - Pure Recursion
    Time Complexity: Exponential (greater than O(2^n) in practice, due to W dimension)
    Space Complexity: O(n + W) in recursion stack (worst case, due to repeated calls)
*/
int maxWeiRec(int idx, int W, vector<int>& wt, vector<int>& val) {
    // Base case
    if (idx == 0) {
        if (W < wt[0]) return 0;
        return (W / wt[0]) * val[0];
    }

    int notPick = maxWeiRec(idx - 1, W, wt, val);

    int pick = -1e9;
    if (wt[idx] <= W)
        pick = val[idx] + maxWeiRec(idx, W - wt[idx], wt, val);

    return max(pick, notPick);
}

/*
    Unbounded Knapsack - Memoization (Top-Down DP)
    Time Complexity: O(n * W)  (each state (idx, W) computed once)
    Space Complexity: O(n * W) for dp table + O(n + W) recursion stack (worst case)
*/
int maxWeiMemo(int idx, int W, vector<int>& wt, vector<int>& val,
               vector<vector<int>>& dp) {

    if (idx == 0) {
        if (W < wt[0]) return 0;
        return (W / wt[0]) * val[0];
    }

    if (dp[idx][W] != -1) return dp[idx][W];

    int notPick = maxWeiMemo(idx - 1, W, wt, val, dp);

    int pick = -1e9;
    if (wt[idx] <= W)
        pick = val[idx] + maxWeiMemo(idx, W - wt[idx], wt, val, dp);

    return dp[idx][W] = max(pick, notPick);
}

int main() {
    // Input is already in the code
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;

    int n = wt.size();

    // Pure Recursion
    int ansRec = maxWeiRec(n - 1, W, wt, val);

    // Memoization
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    int ansMemo = maxWeiMemo(n - 1, W, wt, val, dp);

    cout << "Pure Recursion Answer: " << ansRec << "\n";
    cout << "Memoization Answer:    " << ansMemo << "\n";

    return 0;
}
