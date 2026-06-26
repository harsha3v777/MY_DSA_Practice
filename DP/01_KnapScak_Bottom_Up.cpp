#include <iostream>
#include <vector>
#include <algorithm> // for max
#include <climits>   // for INT_MIN

using namespace std;

class Solution {
public:

    // 1. TABULATION (Bottom-Up DP)
    // Time Complexity: O(N * W)
    // Space Complexity: O(N * W) -> Uses a 2D Array

    int knapsackTabulation(vector<int>& wt, vector<int>& val, int n, int W) {
        // Create a 2D DP table initialized to 0
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base Case: Fill the first row for the first item
        for (int w = wt[0]; w <= W; w++) {
            dp[0][w] = val[0];
        }

        // Loop for remaining items
        for (int idx = 1; idx < n; idx++) {
            for (int wei = 0; wei <= W; wei++) {
                
                int notPick = 0 + dp[idx - 1][wei];
                
                int pick = INT_MIN;
                if (wt[idx] <= wei) {
                    pick = val[idx] + dp[idx - 1][wei - wt[idx]];
                }

                dp[idx][wei] = max(pick, notPick);
            }
        }

        return dp[n - 1][W];
    }


    // 2. SPACE OPTIMIZATION (1D Array)
    // Time Complexity: O(N * W)
    // Space Complexity: O(W) -> Uses a single 1D Array

    int knapsackSpaceOptimized(vector<int>& wt, vector<int>& val, int n, int W) { // ***only 1D DP of single array in which we traverse from left to right side of the array
        // Create a 1D DP array initialized to 0
        vector<int> prev(W + 1, 0);

        for (int w = wt[0]; w <= W; w++) {
            prev[w] = val[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int wei = W; wei >= 0; wei--) {
                
                int notPick = prev[wei];
                
                int pick = INT_MIN;
                if (wt[idx] <= wei) {
                    pick = val[idx] + prev[wei - wt[idx]];
                }

                prev[wei] = max(pick, notPick);
            }
        }

        return prev[W];
    }
};

int main() {

    vector<int> wt = {1, 2, 4, 5};      // Weights of items
    vector<int> val = {5, 4, 8, 6};     // Values of items
    int W = 5;                          // Knapsack Capacity
    int n = wt.size();                  // Number of items

    // Create Solution Object
    Solution sol;

    cout << "--- 0/1 Knapsack Problem ---" << endl;
    cout << "Capacity: " << W << endl;
    cout << "Items (Weight, Value): ";
    for(int i=0; i<n; i++) cout << "(" << wt[i] << "," << val[i] << ") ";
    cout << endl << endl;

    // 1. Run Tabulation
    int resTab = sol.knapsackTabulation(wt, val, n, W);
    cout << "Result (Tabulation O(N*W) Space):      " << resTab << endl;

    // 2. Run Space Optimization
    int resOpt = sol.knapsackSpaceOptimized(wt, val, n, W);
    cout << "Result (Space Optimized O(W) Space):   " << resOpt << endl;

    return 0;
}