#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int x) {
    int n = nums.size();
    int st = 0, end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (x <= nums[mid]) {
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return st;
}

int main() {
    vector<int> nums = {1, 2, 4, 4, 5, 7};

    int x = 5;

    cout << lowerBound(nums, x) << endl;

    return 0;
}