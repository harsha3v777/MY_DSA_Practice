#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size();
        int st = 0, end = n - 1;

        while(st < end) {
            int mid = (st + end) / 2;

            if(nums[mid] > nums[end]) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }

        return st;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};

    int ans = obj.findKRotation(nums);

    cout << "Array: ";
    for(int x : nums) {
        cout << x << " ";
    }

    cout << "\nNumber of rotations: " << ans << endl;

    return 0;
}