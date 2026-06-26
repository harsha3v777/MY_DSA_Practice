#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity (TC):
- O(n^2)

Space Complexity (SC):
- O(n)
  dp[]  -> stores LIS length ending at each index
  hash[] -> stores parent index for reconstruction
  ans[] -> stores the LIS sequence
*/

class Solution {
public:
    vector<int> longestIncreasingSubsequence(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        vector<int> dp(n, 1);
        vector<int> hash(n);

        int maxi = 1;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
        }

        for (int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] > arr[prev]) {
                    if (1 + dp[prev] > dp[i] ||
                       (1 + dp[prev] == dp[i] && arr[prev] < arr[hash[i]])) {
                        dp[i] = 1 + dp[prev];
                        hash[i] = prev;
                    }
                }
            }

            if (dp[i] > maxi || (dp[i] == maxi && arr[i] < arr[idx])) {
                maxi = dp[i];
                idx = i;
            }
        }

        vector<int> ans;
        while (hash[idx] != idx) {
            ans.push_back(arr[idx]);
            idx = hash[idx];
        }
        ans.push_back(arr[idx]);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

void printLIS(vector<int> arr) {
    Solution sol;
    vector<int> lis = sol.longestIncreasingSubsequence(arr);

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nLIS  : ";
    for (int x : lis) cout << x << " ";
    cout << "\n\n";
}

int main() {

    vector<int> arr1 = {1, 3, 5, 4, 7};
    vector<int> arr2 = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    printLIS(arr1);
    printLIS(arr2);

    return 0;
}
