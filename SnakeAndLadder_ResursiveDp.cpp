#include <bits/stdc++.h>
using namespace std;


// TC: O(n²)
// SC: O(n²)

class Solution {
private:
    int sol(int i, int n,
            unordered_map<int, int>& mpl,unordered_map<int, int>& mps,
            vector<int>& dp,vector<int>& path) {

        if (i == n * n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        if (path[i] == 1) {
            return INT_MAX;
        }

        path[i] = 1;

        int curr = i;

        if (mpl.find(curr) != mpl.end()) {
            curr = mpl[curr];
        }

        if (mps.find(curr) != mps.end()) {
            curr = mps[curr];
        }

        int ans = INT_MAX;

        for (int dice = 1; dice <= 6; dice++) {

            int next = curr + dice;

            if (next <= n * n) {

                int temp = sol(next,n,mpl,mps,dp,path);

                if (temp != INT_MAX) {
                    ans = min(ans, 1 + temp);
                }
            }
        }

        path[i] = 0;

        return dp[i] = ans;
    }

public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {

        unordered_map<int, int> mpl;
        unordered_map<int, int> mps;

        // Ladders
        for (int i = 0; i < lad.size(); i += 2) {
            mpl[lad[i]] = lad[i + 1];
        }

        // Snakes
        for (int i = 0; i < sn.size(); i += 2) {
            mps[sn[i]] = sn[i + 1];
        }

        int N = n * n;

        vector<int> dp(N + 1, -1);

        vector<int> path(N + 1, 0);

        return sol(1, n, mpl, mps, dp, path);
    }
};

int main() {

    Solution obj;

    int n = 6;

    // Ladders
    vector<int> lad = {
        2, 15,
        5, 7,
        14, 35,
        22, 30
    };

    // Snakes
    vector<int> sn = {
        17, 4,
        19, 7,
        21, 9,
        27, 1,
        32, 30,
        34, 6
    };

    int ans = obj.minThrows(n, lad, sn);

    cout << "Minimum throws: " << ans << endl;

    return 0;
}