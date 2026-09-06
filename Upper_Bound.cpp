#include <bits/stdc++.h>
using namespace std;

// binary Search
// Tc - O(log n) , Sc - O(1)

int upperBound(vector<int>& nums, int x) {
    int n = nums.size();
    int st = 0, end = n - 1;

    while (st <= end) {
        int mid = (st + end) / 2;

        if (x < nums[mid]) {
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return st;
}

int main() {

    // Example:
    // n = 4
    // nums = [1, 2, 2, 3]
    // x = 2
    // Upper bound = 3

    vector<int> nums = {1, 2, 2, 3};
    int x = 2;

    int ans = upperBound(nums, x);

    cout << "Upper Bound Index: " << ans << endl;

    return 0;
}