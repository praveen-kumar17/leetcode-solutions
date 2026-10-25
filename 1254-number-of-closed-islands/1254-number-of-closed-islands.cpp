class Solution {
public:
    vector<int> drow={-1,1,0,0};
    vector<int>dcol={0,0,-1,1};
    void dfs(int row,int col,vector<vector<int>>& vis ,vector<vector<int>>& grid,int n,int m){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int new_row=row+drow[i];
            int new_col=col+dcol[i];
            if(new_row<n && new_row>=0 && new_col<m && new_col>=0 && grid[new_row][new_col]==0 && !vis[new_row][new_col]){
                dfs(new_row,new_col,vis,grid,n,m);
            }
        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0 && !vis[i][0]) {
                dfs(i, 0, vis, grid, n, m);
            }
            if (grid[i][m - 1] == 0 && !vis[i][m - 1]) {
                dfs(i, m - 1, vis, grid, n, m);
            }
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0 && !vis[0][j]) {
                dfs(0, j, vis, grid, n, m);
            }
            if (grid[n - 1][j] == 0 && !vis[n - 1][j]) {
                dfs(n - 1, j, vis, grid, n, m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    islands++;
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        return islands;
    }
};