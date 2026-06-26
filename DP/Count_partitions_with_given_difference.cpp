#include <bits/stdc++.h>
using namespace std;

/*
Problem: Count number of partitions with given difference
Approach: Bottom-Up Dynamic Programming (Tabulation)
*/

class Solution {
public:
    int countPartitions(int n, int diff, vector<int>& arr) {
        const int mod = 1e9 + 7;
        int totSum=0;

        for(int i=0;i<n;i++){
          totSum+=arr[i];
        }

        if(totSum-diff<0 || (totSum-diff)%2) return 0;
        int tar=(totSum-diff)/2;

        vector<vector<int>> dp(n,vector<int> (tar+1,0));

        if(arr[0]==0){
          dp[0][0]=2;
        }else{
          dp[0][0]=1;
          if(arr[0]<=tar) dp[0][arr[0]]=1;
        }

        for(int i=1;i<n;i++){
          for(int j=0;j<=tar;j++){
            int notPick=dp[i-1][j];
            int pick=0;
            if(arr[i]<=j) pick=dp[i-1][j-arr[i]];

            dp[i][j]=(pick+notPick)%mod;
          }
        }

        return dp[n-1][tar];
    }
};


int main() {
    Solution obj;

    vector<int> arr = {2, 3, 5, 16, 8, 10};
    int diff = 10;
    int n = arr.size();

    cout << "Number of partitions with given difference = "
         << obj.countPartitions(n, diff, arr) << endl;

    return 0;
}

/*
----------------------------------------------
✅ OUTPUT:
Number of partitions with given difference = 3
----------------------------------------------

🧠 TIME COMPLEXITY:
O(n × target)
→ where target = (totalSum - diff) / 2

💾 SPACE COMPLEXITY:
O(n × target)
→ due to 2D DP array

⚙️ Optimizable to O(target) using space-optimized DP (1D array)
----------------------------------------------
*/
