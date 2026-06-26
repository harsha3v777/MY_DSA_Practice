#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

/*
-----------------------------------------------------------------
 1) TABULATION (Bottom-Up DP)
 Time Complexity : O(n * K)
 Space Complexity: O(n * K)
-----------------------------------------------------------------
*/
int tabulation(vector<int> &arr, int K) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(K+1, 0));

    // Base Case
    if(arr[0] == 0) {
        dp[0][0] = 2;  // {} and {0}
    } else {
        dp[0][0] = 1;  // {}
        if(arr[0] <= K) dp[0][arr[0]] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int sum = 0; sum <= K; sum++){
            int notPick = dp[i-1][sum];
            int pick = 0;
            if(arr[i] <= sum)
                pick = dp[i-1][sum - arr[i]];
            dp[i][sum] = (pick + notPick) % MOD;
        }
    }

    return dp[n-1][K];
}

/*
-----------------------------------------------------------------
 2) SPACE OPTIMIZED DP (1D DP)
 Time Complexity : O(n * K)
 Space Complexity: O(K)
-----------------------------------------------------------------
*/
int spaceOptimized(vector<int> &arr, int K) {
    int n = arr.size();
    vector<int> prev(K+1, 0), curr(K+1, 0);

    // Base Case
    if(arr[0] == 0) {
        prev[0] = 2;
    } else {
        prev[0] = 1;
        if(arr[0] <= K) prev[arr[0]] = 1;
    }

    for(int i = 1; i < n; i++){
        curr[0] = (arr[i] == 0) ? (2LL * prev[0] % MOD) : 1;

        for(int sum = 1; sum <= K; sum++){
            int notPick = prev[sum];
            int pick = 0;
            if(arr[i] <= sum) 
                pick = prev[sum - arr[i]];
            curr[sum] = (pick + notPick) % MOD;
        }
        prev = curr;
    }
    return prev[K];
}

int main(){
    // ----------- Input (Change Here to Test) ----------- //
    vector<int> arr = {2, 3, 5, 16, 8, 10};
    int K = 10;
    // --------------------------------------------------- //

    cout << "Array: ";
    for(int x : arr) cout << x << " ";
    cout << "\nTarget Sum K = " << K << "\n\n";

    cout << "Tabulation Result:        " << tabulation(arr, K) << "\n";
    cout << "Space Optimized Result:   " << spaceOptimized(arr, K) << "\n";

    return 0;
}
