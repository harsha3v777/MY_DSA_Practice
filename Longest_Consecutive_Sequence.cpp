#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n log n)
Space Complexity: O(1) auxiliary space
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int ans = 1;
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == nums[i])
                continue;

            if (nums[i - 1] + 1 == nums[i]) {
                cnt++;
            } 
            else {
                cnt = 1;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    Solution obj;

    vector<int> result;
    cout << "Longest Consecutive Sequence: "
         << obj.longestConsecutive(nums) << endl;

    return 0;
}

