#include <iostream>
#include <vector>
#include <algorithm> // for max
#include <climits>   // for INT_MIN

using namespace std;

class Solution {
public:

    // 1. PURE RECURSION
    // Time Complexity: O(2^n) (Exponential)
    // SC : O(N)
    int solveRecursive(int idx, int W, vector<int>& wt, vector<int>& val) {
        // Base Case: First item
        if (idx == 0) {
            if (wt[0] <= W) return val[0];
            else return 0;
        }

        // Logic: Pick or Not Pick  
        int notPick = 0 + solveRecursive(idx - 1, W, wt, val);
        
        int pick = INT_MIN;
        if (wt[idx] <= W) {
            pick = val[idx] + solveRecursive(idx - 1, W - wt[idx], wt, val);
        }

        return max(pick, notPick);
    }

    // Wrapper for Recursion
    int knapsackPureRecursion(vector<int>& wt, vector<int>& val, int n, int W) {
        return solveRecursive(n - 1, W, wt, val);
    }


    // 2. MEMOIZATION (Top-Down DP)
    // Time Complexity: O(N * W)
    // SC : O(N * W) + O(N)
    int solveMemo(int idx, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
        // Base Case: First item
        if (idx == 0) {
            if (wt[0] <= W) return val[0];
            else return 0;
        }

        // Step 2: Check if the state is already computed
        if (dp[idx][W] != -1) return dp[idx][W];

        // Logic: Pick or Not Pick
        int notPick = 0 + solveMemo(idx - 1, W, wt, val, dp);
        
        int pick = INT_MIN;
        if (wt[idx] <= W) {
            pick = val[idx] + solveMemo(idx - 1, W - wt[idx], wt, val, dp);
        }

        // Step 3: Store the result in DP table
        return dp[idx][W] = max(pick, notPick);
    }

    // Wrapper for Memoization
    int knapsackMemoization(vector<int>& wt, vector<int>& val, int n, int W) {
        // Step 1: Create DP table initialized with -1
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solveMemo(n - 1, W, wt, val, dp);
    }
};

int main() {

    vector<int> wt = {3, 4, 5};     // Weights of items
    vector<int> val = {30, 50, 60}; // Values of items
    int W = 8;                      // Knapsack Capacity
    int n = wt.size();              // Number of items

    // Create Solution Object
    Solution sol;

    cout << "--- 0/1 Knapsack Problem ---" << endl;
    cout << "Capacity: " << W << endl;
    cout << "Items (Weight, Value): ";
    for(int i=0; i<n; i++) cout << "(" << wt[i] << "," << val[i] << ") ";
    cout << endl << endl;

    // 1. Run Pure Recursion
    int resRec = sol.knapsackPureRecursion(wt, val, n, W);
    cout << "Result (Pure Recursion): " << resRec << endl;

    // 2. Run Memoization
    int resMemo = sol.knapsackMemoization(wt, val, n, W);
    cout << "Result (Memoization):    " << resMemo << endl;

    return 0;
}