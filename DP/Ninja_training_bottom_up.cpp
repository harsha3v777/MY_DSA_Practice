#include <bits/stdc++.h>
using namespace std;

/*
   Problem: Ninja Training (Maximum Points)
   ---------------------------------------
   A Ninja can perform one of three activities each day.
   He cannot perform the same activity on two consecutive days.
   Each activity gives some points, and we must maximize total points.
*/

// ==================== TABULATION (Bottom-Up DP) ====================
// | Version         | Time Complexity         | Space Complexity    |
// | --------------- | ----------------------- | ------------------- |
// | Tabulation      | O(n × 4 × 3) → **O(n)** | O(4n) → **O(n)**    |
// | Space Optimized | O(n × 4 × 3) → **O(n)** | O(4 + 4) → **O(1)** |

int ninjaTrainingTabulation(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case for day 0
    dp[0][0] = max(matrix[0][1], matrix[0][2]);
    dp[0][1] = max(matrix[0][0], matrix[0][2]);
    dp[0][2] = max(matrix[0][0], matrix[0][1]);
    dp[0][3] = max({matrix[0][0], matrix[0][1], matrix[0][2]});

    // Fill DP table for remaining days
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int points = matrix[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], points);
                }
            }
        }
    }

    return dp[n - 1][3];
}

// ==================== SPACE OPTIMIZED DP ====================
int ninjaTrainingSpaceOptimized(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prev(4, 0);

    // Base case
    prev[0] = max(matrix[0][1], matrix[0][2]);
    prev[1] = max(matrix[0][0], matrix[0][2]);
    prev[2] = max(matrix[0][0], matrix[0][1]);
    prev[3] = max({matrix[0][0], matrix[0][1], matrix[0][2]});

    // Iterate over days
    for (int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++) {
            temp[last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int points = matrix[day][task] + prev[task];
                    temp[last] = max(temp[last], points);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}

// ==================== MAIN FUNCTION ====================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example Input
    vector<vector<int>> matrix = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << "===== NINJA TRAINING PROBLEM =====\n\n";

    cout << "Activities Points Table:\n";
    for (int i = 0; i < matrix.size(); i++) {
        cout << "Day " << i + 1 << ": ";
        for (int val : matrix[i]) cout << val << " ";
        cout << "\n";
    }
    cout << "\n";

    cout << "✅ Using Tabulation (Bottom-Up DP): " 
         << ninjaTrainingTabulation(matrix) << "\n";
    cout << "✅ Using Space Optimized DP: " 
         << ninjaTrainingSpaceOptimized(matrix) << "\n";

    return 0;
}
