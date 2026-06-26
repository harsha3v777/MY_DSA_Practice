// TC: O(n * m)
// SC: O(n * m)

#include <bits/stdc++.h>
using namespace std;

string findLCS(int n, int m, const string &s1, const string &s2){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int len = dp[n][m];
    string s(len, '$');
    int index = len - 1;

    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            s[index] = s1[i-1];
            --index;
            --i; --j;
        } else if(dp[i-1][j] > dp[i][j-1]){
            --i;
        } else {
            --j;
        }
    }
    return s;
}

int main() {
    string s1 = "abcde";   // <-- INPUT LINE 1
    string s2 = "ace";     // <-- INPUT LINE 2

    cout << findLCS(s1.size(), s2.size(), s1, s2);
    return 0;
}
