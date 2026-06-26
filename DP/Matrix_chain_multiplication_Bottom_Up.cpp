#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Time Complexity (TC): O(N^3)
        - Three nested loops:
            i → N
            j → N
            k → N
        => O(N * N * N) = O(N^3)

    Space Complexity (SC): O(N^2)
        - DP table of size N x N
    */

    int matrixMultiplication(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j < n; j++) {
                int mini = INT_MAX;

                for (int k = i; k < j; k++) {
                    int temp = nums[i - 1] * nums[k] * nums[j]
                               + dp[i][k] + dp[k + 1][j];

                    mini = min(mini, temp);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }
};

int main() {
    Solution obj;

    vector<int> nums = {10, 20, 30, 40};

    int result = obj.matrixMultiplication(nums);

    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}