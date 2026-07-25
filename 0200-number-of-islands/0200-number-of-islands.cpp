class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>& vis,int n,int m){
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]=='0' || vis[row][col]){
            return;
        }
        vis[row][col]=true;
            dfs(row-1,col,grid,vis,n,m);
            dfs(row,col+1,grid,vis,n,m);
            dfs(row+1,col,grid,vis,n,m);
            dfs(row,col-1,grid,vis,n,m);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};