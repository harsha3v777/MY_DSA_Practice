#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int maxi = nums[n - 1];
        ans.push_back(maxi);

        for (int i = n - 2; i >= 0; i--) {
            if (maxi < nums[i]) {
                maxi = nums[i];
                ans.push_back(nums[i]);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    Solution obj;

    vector<int> ans = obj.leaders(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}