#include <bits/stdc++.h>
using namespace std;

class Solution{  
public:

    // 1️⃣ Normal 2D DP approach
    bool isSubsetSum2D(vector<int> arr, int target){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(arr[0] <= target) dp[0][arr[0]] = true;

        for(int idx = 1; idx < n; idx++){
            for(int tar = 1; tar <= target; tar++){
                bool notTake = dp[idx - 1][tar];
                bool take = false;
                if(arr[idx] <= tar)
                    take = dp[idx - 1][tar - arr[idx]];
                dp[idx][tar] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }

    // 2️⃣ Space-optimized 1D DP approach
    bool isSubsetSum1D(vector<int> arr, int target){
        int n = arr.size();
        vector<bool> prev(target + 1, false), curr(target + 1, false);

        prev[0] = curr[0] = true;
        if(arr[0] <= target)
            prev[arr[0]] = true;

        for(int idx = 1; idx < n; idx++){
            curr[0] = true;
            for(int tar = 1; tar <= target; tar++){
                bool notTake = prev[tar];
                bool take = false;
                if(arr[idx] <= tar)
                    take = prev[tar - arr[idx]];
                curr[tar] = take || notTake;
            }
            prev = curr;
        }

        return prev[target];
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 7, 3};
    int target = 6;

    cout << "Using 2D DP: ";
    cout << (sol.isSubsetSum2D(arr, target) ? "True" : "False") << endl;

    cout << "Using 1D Optimized DP: ";
    cout << (sol.isSubsetSum1D(arr, target) ? "True" : "False") << endl;

    return 0;
}
