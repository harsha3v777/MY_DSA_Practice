#include <bits/stdc++.h>
using namespace std;

// TC: O(n²)
// SC: O(n²)

class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {

        int N = n * n;

        // Store snakes and ladders as:
        // start -> destination
        unordered_map<int, int> jump;

        // Ladders
        for (int i = 0; i < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }

        // Snakes
        for (int i = 0; i < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }

        // dist[i] = minimum throws needed to reach cell i
        vector<int> dist(N + 1, -1);

        queue<int> q;

        // Start from cell 1
        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            // Reached final cell
            if (curr == N)
                return dist[curr];

            // Try all possible dice values
            for (int dice = 1; dice <= 6; dice++) {

                int next = curr + dice;

                if (next > N)
                    continue;

                // If snake/ladder exists, jump
                if (jump.find(next) != jump.end()) {
                    next = jump[next];
                }

                // Visit only if not visited before
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};


int main() {

    Solution obj;

    int n = 6;

    // Ladder:
    // 2 -> 15
    // 5 -> 7
    // 14 -> 35
    // 22 -> 41
    // 25 -> 31
    // 38 -> 51
    vector<int> lad = {
        2, 15,
        5, 7,
        14, 35,
        22, 41,
        25, 31,
        38, 51
    };

    // Snake:
    // 17 -> 4
    // 19 -> 7
    // 21 -> 9
    // 27 -> 1
    // 32 -> 30
    // 34 -> 6
    // 62 -> 60
    // etc. depending on board
    vector<int> sn = {
        17, 4,
        19, 7,
        21, 9,
        27, 1,
        32, 30,
        34, 6
    };

    cout << "Minimum throws: "
         << obj.minThrows(n, lad, sn)
         << endl;

    return 0;
}