#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // --- 1️⃣ PURE RECURSIVE METHOD ---
    bool subsetSumRecursive(vector<int>& arr, int target, int idx) {
        if (target == 0) return true;
        if (idx == 0) return arr[0] == target;

        bool notTake = subsetSumRecursive(arr, target, idx - 1);
        bool take = false;
        if (arr[idx] <= target)
            take = subsetSumRecursive(arr, target - arr[idx], idx - 1);

        return take || notTake;
    }

    // --- 2️⃣ MEMOIZED (TOP-DOWN DP) METHOD ---
    bool subsetSumMemo(vector<int>& arr, int target, int idx, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (idx == 0) return arr[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool notTake = subsetSumMemo(arr, target, idx - 1, dp);
        bool take = false;
        if (arr[idx] <= target)
            take = subsetSumMemo(arr, target - arr[idx], idx - 1, dp);

        return dp[idx][target] = take || notTake;
    }

public:
    // --- Calls the PURE RECURSIVE VERSION ---
    bool isSubsetSumRecursive(vector<int> arr, int target) {
        int n = arr.size();
        return subsetSumRecursive(arr, target, n - 1);
    }

    // --- Calls the MEMOIZED VERSION ---
    bool isSubsetSumMemo(vector<int> arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return subsetSumMemo(arr, target, n - 1, dp);
    }
};

// --- MAIN FUNCTION TO TEST BOTH METHODS ---
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 7, 3};
    int target = 6;

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTarget: " << target << "\n\n";

    cout << "Recursive Result: "
         << (sol.isSubsetSumRecursive(arr, target) ? "True" : "False") << "\n";

    cout << "Memoized Result: "
         << (sol.isSubsetSumMemo(arr, target) ? "True" : "False") << "\n";

    return 0;
}
