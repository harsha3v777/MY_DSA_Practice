#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
===========================================================
Problem:
Longest Subarray with Sum = K
===========================================================

Approach 1: Brute Force

Time Complexity : O(n^2)
Space Complexity: O(1)

Works for:
✔ Positive numbers
✔ Zero
✔ Negative numbers
===========================================================
*/

int bruteForce(vector<int> &nums, int k){
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++){
        int sum = 0;

        for (int j = i; j < n; j++){
            sum += nums[j];

            if (sum == k){
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

/*
===========================================================
Approach 2: Better (Prefix Sum + Hash Map)

Time Complexity : O(n)
Space Complexity: O(n)

Works for:
✔ Positive numbers
✔ Zero
✔ Negative numbers
===========================================================
*/

int better(vector<int> &nums, int k){
    unordered_map<int, int> prefixMap;

    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); i++){
        sum += nums[i];

        if (sum == k)
            maxLen = i + 1;

        int rem = sum - k;

        if (prefixMap.find(rem) != prefixMap.end()){
            int len = i - prefixMap[rem];
            maxLen = max(maxLen, len);
        }

        if (prefixMap.find(sum) == prefixMap.end()){
            prefixMap[sum] = i;
        }
    }

    return maxLen;
}

/*
===========================================================
Approach 3: Optimal (Sliding Window)

Time Complexity : O(n)
Space Complexity: O(1)

Works for:
✔ Positive numbers
✔ Positive + Zero

Does NOT work for:
✘ Negative numbers
===========================================================
*/

int optimal(vector<int> &nums, int k){
    int n = nums.size();

    int left = 0;
    int sum = 0;
    int maxLen = 0;

    for (int right = 0; right < n; right++){
        sum += nums[right];

        while (left <= right && sum > k){
            sum -= nums[left];
            left++;
        }

        if (sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

void printArray(vector<int> &arr){
    cout << "{ ";

    for (int x : arr)
        cout << x << " ";

    cout << "}";
}

int main(){

    vector<int> nums1 = {1, 2, 3, 1, 1, 1, 1, 4, 2};
    int k1 = 3;

    cout << "=============================================\n";
    cout << "TEST CASE 1 (Positive Numbers)\n";
    cout << "Array : ";
    printArray(nums1);
    cout << "\nK = " << k1 << "\n\n";

    cout << "Brute Force : " << bruteForce(nums1, k1) << endl;
    cout << "Better      : " << better(nums1, k1) << endl;
    cout << "Optimal     : " << optimal(nums1, k1) << endl;


    vector<int> nums2 = {2, -1, 2, 3, -2, 4};
    int k2 = 8;

    cout << "\n\n=============================================\n";
    cout << "TEST CASE 2 (Negative Numbers)\n";
    cout << "Array : ";
    printArray(nums2);
    cout << "\nK = " << k2 << "\n\n";

    cout << "Brute Force : " << bruteForce(nums2, k2) << endl;
    cout << "Better      : " << better(nums2, k2) << endl;

    cout << "Optimal (Sliding Window) : NOT APPLICABLE\n";

    return 0;
}