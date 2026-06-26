#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  private:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int delRow=-1;delRow<=1;delRow++){
                for (int delCol = -1; delCol <=1; delCol++){
                    int nrow=row+delRow;
                    int ncol=col+delCol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
                
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    islands++;
                }
            }
        }

        return islands;
        
    }
};


int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'0', '0', '0', '0', '0'},
        {'1', '0', '1', '0', '1'}
    };

    Solution sol;
    cout << "Number of islands: " << sol.countIslands(grid) << endl;

    return 0;
}