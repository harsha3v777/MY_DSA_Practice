#include <bits/stdc++.h>
using namespace std;

// Time: O(n²)
// Space: O(n)

// Bitonic can be purely incresing (or) purely Decresing (or) incresing and decresing

class Solution {
public:
    int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();

        vector<int> dp1(n, 1);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] > arr[prev] && dp1[prev] + 1 > dp1[i]) {
                    dp1[i] = dp1[prev] + 1;
                }
            }
        }

        vector<int> dp2(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = n - 1; prev > i; prev--) {
                if (arr[i] > arr[prev] && dp2[prev] + 1 > dp2[i]) {
                    dp2[i] = dp2[prev] + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp1[i] + dp2[i] - 1);
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};

    Solution obj;
    cout << obj.LongestBitonicSequence(arr);

    return 0;
}
