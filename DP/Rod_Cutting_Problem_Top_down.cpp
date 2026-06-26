#include <bits/stdc++.h>
using namespace std;

class Solution {

    /* Pure Recursion
       Time:  O(2^n)
       Space: O(n)
    */
    int maxPriceRec(int idx, int len, vector<int> &price) {
        if (idx == 0)
            return len * price[0];

        int notPick = maxPriceRec(idx - 1, len, price);

        int pick = INT_MIN;
        int rodLen = idx + 1;
        if (len >= rodLen)
            pick = price[idx] + maxPriceRec(idx, len - rodLen, price);

        return max(pick, notPick);
    }

    /* Memoization (Top-Down DP)
       Time:  O(n^2)
       Space: O(n^2) + O(n) recursion
    */
    int maxPriceMemo(int idx, int len, vector<int> &price, vector<vector<int>> &dp) {
        if (idx == 0)
            return len * price[0];

        if (dp[idx][len] != -1)
            return dp[idx][len];

        int notPick = maxPriceMemo(idx - 1, len, price, dp);

        int pick = INT_MIN;
        int rodLen = idx + 1;
        if (len >= rodLen)
            pick = price[idx] + maxPriceMemo(idx, len - rodLen, price, dp);

        return dp[idx][len] = max(pick, notPick);
    }

public:
    int rodCuttingRecursion(vector<int> &price, int n) {
        int s = price.size();
        return maxPriceRec(s - 1, n, price);
    }

    int rodCuttingMemoization(vector<int> &price, int n) {
        int s = price.size();
        vector<vector<int>> dp(s, vector<int>(n + 1, -1));
        return maxPriceMemo(s - 1, n, price, dp);
    }
};

int main() {
    vector<int> price = {1, 6, 8, 9, 10, 19, 7, 20};
    int n = 8;

    Solution sol;

    cout << "Pure Recursion Output: " 
         << sol.rodCuttingRecursion(price, n) << "\n";

    cout << "Memoization Output:    " 
         << sol.rodCuttingMemoization(price, n) << "\n";

    return 0;
}
