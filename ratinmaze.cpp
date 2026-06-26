#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &maze, int row, int col, string path, vector<string> &ans, vector<vector<bool>> &inv) {
    int n = maze.size();

    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || inv[row][col]) {
        return;
    }

    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    inv[row][col] = true;

    helper(maze, row, col + 1, path + "R", ans, inv); // Right
    helper(maze, row + 1, col, path + "D", ans, inv); // Down
    helper(maze, row, col - 1, path + "L", ans, inv); // Left
    helper(maze, row - 1, col, path + "U", ans, inv); // Up

    inv[row][col] = false;
}

vector<string> findPath(vector<vector<int>> &maze) {
    vector<string> ans;
    int n = maze.size();
    
    if (maze[0][0] == 0) return ans;

    vector<vector<bool>> inv(n, vector<bool>(n, false));

    helper(maze, 0, 0, "", ans, inv);

    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans = findPath(maze);

    for (string path : ans) {
        cout << path << endl;
    }

    return 0;
}
