#include <bits/stdc++.h>
using namespace std;

// TOP DOWN Apporach

// -------------------------------------------
// 🚀 Pure Recursion (Exponential time)
// Time Complexity: O(2^n)   [Every index branches into 2 calls]
// Space Complexity: O(n)    [Recursion call stack depth]
// -------------------------------------------
class SolutionRecursive {
public:
    int rec(int idx, vector<int>& heights) {
        if (idx == 0) return 0; // Base case

        // Option 1: Jump from (idx-1)
        int left = rec(idx - 1, heights) + abs(heights[idx] - heights[idx - 1]);

        // Option 2: Jump from (idx-2) if possible
        int right = INT_MAX;
        if (idx > 1) {
            right = rec(idx - 2, heights) + abs(heights[idx] - heights[idx - 2]);
        }

        return min(left, right);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        return rec(n - 1, heights);
    }
};

// -------------------------------------------
// 🚀 Recursion + Memoization (Top-Down DP)
// Time Complexity: O(n)     [Each state solved once, then cached]
// Space Complexity: O(n)    [dp array + recursion stack]
// -------------------------------------------
class SolutionMemo {
public:
    int rec(int idx, vector<int>& heights, vector<int>& dp) {
        if (idx == 0) return 0;              // Base case
        if (dp[idx] != -1) return dp[idx];   // Already computed

        // Option 1: Jump from (idx-1)
        int left = rec(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);

        // Option 2: Jump from (idx-2), if possible
        int right = INT_MAX;
        if (idx > 1) {
            right = rec(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
        }

        return dp[idx] = min(left, right);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, -1); // Memo table
        return rec(n - 1, heights, dp);
    }
};

// -------------------------------------------
// 🔹 Driver Code
// -------------------------------------------
int main() {
    vector<int> heights1 = {2, 1, 3, 5, 4};
    vector<int> heights2 = {7, 5, 1, 2, 6};

    SolutionRecursive solRec;
    SolutionMemo solMemo;

    cout << "Test Case 1 (Pure Recursion): " << solRec.frogJump(heights1) << endl;
    cout << "Test Case 1 (Memoization): " << solMemo.frogJump(heights1) << endl;

    cout << "Test Case 2 (Pure Recursion): " << solRec.frogJump(heights2) << endl;
    cout << "Test Case 2 (Memoization): " << solMemo.frogJump(heights2) << endl;

    return 0;
}
