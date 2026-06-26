#include <bits/stdc++.h>
using namespace std;

/*
    Unbounded Knapsack - Tabulation (Bottom-Up)

    Time Complexity:  O(n * W)
    Space Complexity: O(n * W)
*/
int unboundedKnapsackTabulation(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base Case: First item filled for all capacities
    for (int w = 0; w <= W; w++) {
        dp[0][w] = (w / wt[0]) * val[0];
    }

    for (int idx = 1; idx < n; idx++) {
        for (int w = 0; w <= W; w++) {
            int notPick = dp[idx - 1][w];
            int pick = -1e9;
            if (wt[idx] <= w)
                pick = val[idx] + dp[idx][w - wt[idx]]; // idx again because unbounded

            dp[idx][w] = max(pick, notPick);
        }
    }

    return dp[n - 1][W];
}

/*
    Unbounded Knapsack - Space Optimization (1D DP)

    Time Complexity:  O(n * W)
    Space Complexity: O(W)
*/
int unboundedKnapsackSpaceOpt(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<int> dp(W + 1, 0);

    // Base Case for first item
    for (int w = 0; w <= W; w++) {
        dp[w] = (w / wt[0]) * val[0];
    }

    for (int idx = 1; idx < n; idx++) {
        for (int w = 0; w <= W; w++) {
            int notPick = dp[w];
            int pick = -1e9;
            if (wt[idx] <= w)
                pick = val[idx] + dp[w - wt[idx]];

            dp[w] = max(pick, notPick);
        }
    }

    return dp[W];
}

int main() {
    // Input already in the code
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;

    int n = wt.size();

    int ansTab = unboundedKnapsackTabulation(wt, val, n, W);
    int ansSpace = unboundedKnapsackSpaceOpt(wt, val, n, W);

    cout << "Tabulation Answer:       " << ansTab << "\n";
    cout << "Space Optimized Answer:  " << ansSpace << "\n";

    return 0;
}
