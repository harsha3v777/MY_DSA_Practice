#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
===========================================================
Problem:
Maximum Subarray Sum 
===========================================================
Approach 1 : Brute Force

Time Complexity : O(n^2)
Space Complexity: O(1)

Works for:
✔ Positive
✔ Negative
✔ Zero
===========================================================
*/

int bruteForce(vector<int> &nums){
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++){
        int sum = 0;

        for (int j = i; j < n; j++){
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

/*
===========================================================
Approach 2 : Kadane's Algorithm (Optimal)

Time Complexity : O(n)
Space Complexity: O(1)

Works for:
✔ Positive
✔ Negative
✔ Zero
===========================================================
*/

int kadane(vector<int> &nums){
    int n = nums.size();

    int currSum = 0;
    int maxSum = INT_MIN;

    int start = 0;
    int end = 0;
    int tempStart = 0;

    for (int i = 0; i < n; i++){
        currSum += nums[i];

        if (currSum > maxSum){
            maxSum = currSum;
            start = tempStart;
            end = i;
        }

        if (currSum < 0){
            currSum = 0;
            tempStart = i + 1;
        }
    }

    cout << "Maximum Subarray : ";

    for (int i = start; i <= end; i++){
        cout << nums[i] << " ";
    }

    cout << endl;

    return maxSum;
}

void printArray(vector<int> &nums){
    cout << "{ ";

    for (int x : nums)
        cout << x << " ";

    cout << "}";
}

int main(){
    /*
    Example:
    Maximum Subarray:
    {4, -1, 2, 1}

    Maximum Sum = 6
    */

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "=====================================\n";
    cout << "Maximum Subarray Sum (Kadane's Algorithm)\n";
    cout << "=====================================\n\n";

    cout << "Array : ";
    printArray(nums);
    cout << "\n\n";

    cout << "Brute Force Answer : "
         << bruteForce(nums) << endl;

    cout << "Kadane's Answer     : "
         << kadane(nums) << endl;

    return 0;
}