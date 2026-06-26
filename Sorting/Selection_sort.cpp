#include <iostream>
#include <vector>
using namespace std;

// T.C - O(n^2) and S.C - O(1)
// Not Stable,Inplace, Not Adaptive

vector<int> selectionSort(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        int mini = i;

        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[mini]) {
                mini = j;
            }
        }

        // swap(nums[i],nums[mini]);
        int temp = nums[i];
        nums[i] = nums[mini];
        nums[mini] = temp;
    }

    return nums;
}

int main() {
    vector<int> nums = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    selectionSort(nums);

    cout << "Sorted Array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}