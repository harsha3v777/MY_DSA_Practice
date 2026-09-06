#include <bits/stdc++.h>
using namespace std;

// ---------------- FIRST CODE ----------------
vector<int> firstApproach(vector<int> nums, int x) {
    int n = nums.size();
    int st = 0, end = n - 1;
    vector<int> ans;

    // Floor
    while(st <= end) {
        int mid = (st + end) / 2;

        if(x < nums[mid]) {
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    if(end >= 0) {
        ans.push_back(nums[end]);
    } else {
        ans.push_back(-1);
    }

    // Ceil
    st = 0;
    end = n - 1;

    while(st <= end) {
        int mid = (st + end) / 2;

        if(x <= nums[mid]) {
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    if(st < n) {
        ans.push_back(nums[st]);
    } else {
        ans.push_back(-1);
    }

    return ans;
}


// ---------------- SECOND CODE ----------------
vector<int> secondApproach(vector<int> nums, int x) {
    int n = nums.size();
    int st = 0, end = n - 1;
    int floor = -1, ceil = -1;

    while(st <= end) {
        int mid = (st + end) / 2;

        if(nums[mid] == x) {
            return {x, x};
        }

        if(x < nums[mid]) {
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    floor = end >= 0 ? nums[end] : -1;
    ceil = st < n ? nums[st] : -1;

    return {floor, ceil};
}


// ---------------- MAIN ----------------
int main() {

    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5;

    vector<int> ans1 = firstApproach(nums, x);
    vector<int> ans2 = secondApproach(nums, x);

    cout << "First Approach: ";
    cout << ans1[0] << " " << ans1[1] << endl;

    cout << "Second Approach: ";
    cout << ans2[0] << " " << ans2[1] << endl;

    return 0;
}