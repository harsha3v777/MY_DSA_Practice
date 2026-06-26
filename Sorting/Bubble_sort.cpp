#include <iostream>
#include <vector>
using namespace std;

// T.C - O(n^2) and S.C - O(1)
// Stable, Inplace, Adaptive
vector<int> bubbleSort(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) { // i=n-1,i>=0;i--
        for (int j = 0; j < n - i - 1; j++) { // j=0;j<=i-1;j++
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }

    return nums;
}

int main() {
    vector<int> nums = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original Array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    bubbleSort(nums);

    cout << "Sorted Array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}