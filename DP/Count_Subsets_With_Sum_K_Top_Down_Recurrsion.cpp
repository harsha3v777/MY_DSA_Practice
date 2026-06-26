#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

/*
-------------------------------------------------------
 PURE RECURSION
 Time Complexity:  O(2^n)
 Space Complexity: O(n)  (due to recursion stack)
-------------------------------------------------------
*/
int pureRecursion(int idx, int sum, vector<int> &arr) {
    if(sum == 0) return 1;            // empty subset forms sum 0
    if(idx < 0) return 0;            // no elements left
    
    int notPick = pureRecursion(idx - 1, sum, arr);
    int pick = 0;
    if(arr[idx] <= sum)
        pick = pureRecursion(idx - 1, sum - arr[idx], arr);

    return (pick + notPick) % MOD;
}

/*
-------------------------------------------------------
 MEMOIZATION (Top-Down DP)
 Time Complexity:  O(n * K)
 Space Complexity: O(n * K) DP + O(n) stack
-------------------------------------------------------
*/
vector<vector<int>> dp;

int memoRecursion(int idx, int sum, vector<int> &arr) {
    if(sum == 0) return 1;
    if(idx == 0) return (arr[0] == sum) ? 1 : 0;

    if(dp[idx][sum] != -1) return dp[idx][sum];

    int notPick = memoRecursion(idx - 1, sum, arr) % MOD;
    int pick = 0;
    if(arr[idx] <= sum) 
        pick = memoRecursion(idx - 1, sum - arr[idx], arr) % MOD;

    return dp[idx][sum] = (pick + notPick) % MOD;
}

int main() {

    // ----------- Input (Change here for testing) ----------- //
    vector<int> arr = {2, 3, 5, 16, 8, 10};
    int K = 10;
    int n = arr.size();
    // -------------------------------------------------------- //

    cout << "Array: ";
    for(int x : arr) cout << x << " ";
    cout << "\nTarget Sum K = " << K << "\n\n";

    // PURE RECURSION CALL
    cout << "Pure Recursion Result: ";
    cout << pureRecursion(n - 1, K, arr) << "\n";

    // MEMOIZATION CALL
    dp.assign(n, vector<int>(K + 1, -1));
    cout << "Memoization Result:   ";
    cout << memoRecursion(n - 1, K, arr) << "\n";

    return 0;
}
