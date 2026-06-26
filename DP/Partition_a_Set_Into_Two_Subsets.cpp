#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minDifference(vector<int>& arr, int n)  { 
        
        int tot = 0;
        for(int i = 0; i < n; i++){
            tot += arr[i];
        }

        vector<bool> prev(tot+1, false), curr(tot+1, false);

        prev[0] = true;
        if(arr[0] <= tot) prev[arr[0]] = true;

        for(int i = 1; i < n; i++){
            // curr.assign(tot+1, false);  // Reset curr array - no need may be same result
            curr[0] = true;

            for(int target = 1; target <= tot; target++){
                bool notTake = prev[target];
                bool take = false;

                if(target >= arr[i]) 
                    take = prev[target - arr[i]];

                curr[target] = take || notTake;
            }
            prev = curr;
        }

        int ans = INT_MAX;
        for(int tar = 0; tar <= tot; tar++){
            if(prev[tar] == true){
                int sum1 = tar;
                int sum2 = tot - tar;
                ans = min(ans, abs(sum2 - sum1));
            }
        }

        return ans;
    } 
};

int main(){
    // Example array
    vector<int> arr = {1, 6, 11, 5};
    int n = arr.size();

    Solution obj;
    int result = obj.minDifference(arr, n);

    cout << "Minimum Difference: " << result << endl;

    return 0;
}
