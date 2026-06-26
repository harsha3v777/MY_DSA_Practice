#include <bits/stdc++.h>
using namespace std;

/*
   Problem: Maximum Points (Ninja Training)
   - Each day, a person can perform one of three activities.
   - The same activity cannot be done on two consecutive days.
   - Goal: Maximize total points over n days.
*/

// ==================== PURE RECURSION ====================
// tc - O(3^n) , sc - O(n)
int maxPointsRec(int day, int last, vector<vector<int>>& arr) {
    if (day == 0) {
        int points = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last)
                points = max(points, arr[0][i]);
        }
        return points;
    }

    int points = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int pt = arr[day][i] + maxPointsRec(day - 1, i, arr);
            points = max(points, pt);
        }
    }

    return points;
}

// ==================== DP (MEMOIZATION) ====================
// tc - O(n*4*3) , sc - O(n)+O(4*n)
int maxPointsDP(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if (day == 0) {
        int points = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last)
                points = max(points, arr[0][i]);
        }
        return points;
    }

    if (dp[day][last] != -1)
        return dp[day][last];

    int points = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int pt = arr[day][i] + maxPointsDP(day - 1, i, arr, dp);
            points = max(points, pt);
        }
    }

    return dp[day][last] = points;
}

int maximumPointsRecursion(vector<vector<int>>& arr) {
    int n = arr.size();
    return maxPointsRec(n - 1, 3, arr);
}

int maximumPointsDP(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return maxPointsDP(n - 1, 3, arr, dp);
}

// ==================== MAIN FUNCTION ====================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example Input
    vector<vector<int>> arr = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << "===== Maximum Points Problem =====\n";
    cout << "Using Pure Recursion: " << maximumPointsRecursion(arr) << "\n";
    cout << "Using DP (Memoization): " << maximumPointsDP(arr) << "\n";

    return 0;
}
