#include <bits/stdc++.h>
using namespace std;

/*
    Longest Common Substring
    Time Complexity (TC):  O(n1 * n2)
    Space Complexity (SC): O(n1 * n2)
*/

class Solution {
public:
    int longestCommonSubstr(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int ans = 0;

        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

int main() {

    // Input strings defined inside this same file
    string str1 = "abcdxyz";
    string str2 = "xyzabcd";

    Solution sol;
    int ans = sol.longestCommonSubstr(str1, str2);

    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    cout << "Longest Common Substring Length = " << ans << endl;

    return 0;
}
