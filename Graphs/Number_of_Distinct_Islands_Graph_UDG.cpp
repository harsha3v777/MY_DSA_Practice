#include <bits/stdc++.h>

using namespace std;

//t.c => O(n*m*log(set length=>(n*m)))+O(n*m*4)
class Solution {
private:
    void DFS(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid, vector<pair<int,int>>& vec,
             int row0, int col0) {
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0}); // relative position
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        for(int k = 0; k < 4; k++) {
            int nrow = row + delRow[k];
            int ncol = col + delCol[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
               vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                DFS(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> set1;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1) {
                    vector<pair<int,int>> vec;
                    DFS(i, j, vis, grid, vec, i, j);
                    set1.insert(vec);
                }
            }
        }
        
        return set1.size();
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 1, 0, 1, 0}
    };

    Solution obj;
    int ans = obj.countDistinctIslands(grid);
    cout << "Number of distinct islands: " << ans << endl;
    
    return 0;
}
