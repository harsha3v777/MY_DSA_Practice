#include <bits/stdc++.h>
using namespace std;


// using binary search - O(log n)

class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) {
        int n = arr.size();
        int st = 0, end = n - 1;

        // Find first occurrence
        while(st <= end) {
            int mid = (st + end) / 2;

            if(target <= arr[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        int first = st;

        // Target not present
        if(first == n || arr[first] != target) {
            return -1;
        }

        // Find last occurrence
        st = 0;
        end = n - 1;

        while(st <= end) {
            int mid = (st + end) / 2;

            if(target < arr[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        int last = st - 1;

        return last - first + 1;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int target = 2;

    int ans = obj.countOccurrences(arr, target);

    cout << "Array: ";
    for(int x : arr) {
        cout << x << " ";
    }

    cout << "\nTarget: " << target << endl;
    cout << "Occurrences: " << ans << endl;

    return 0;
}