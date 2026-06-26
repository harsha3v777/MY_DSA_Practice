#include <bits/stdc++.h>
using namespace std;

/*
Matrix Chain Multiplication using Memoization (Top-Down DP)

Time Complexity (TC): O(N^3)
- There are O(N^2) states (i, j)
- For each state we try N partitions (k)

Space Complexity (SC): O(N^2) + O(N)
- O(N^2) for DP table
- O(N) recursion stack
*/

class Solution {

private:

    int minMult(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {

        if (i == j) 
            return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        int mini = 1e9;

        for (int k = i; k <= j - 1; k++) {

            int steps = nums[i-1] * nums[k] * nums[j] +
                        minMult(i, k, nums, dp) +
                        minMult(k + 1, j, nums, dp);

            mini = min(mini, steps);
        }

        return dp[i][j] = mini;
    }

public:

    int matrixMultiplication(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return minMult(1, n - 1, nums, dp);
    }
};


int main() {

    Solution obj;

    // Example Input
    vector<int> nums = {10, 20, 30, 40, 50};

    int result = obj.matrixMultiplication(nums);

    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}