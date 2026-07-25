class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& board,vector<vector<int>>& vis,int n,int m,int drow[],int dcol[]){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int n_row=row+drow[i];
            int n_col=col+dcol[i];
            if(n_row>=0 && n_col>=0 && n_row<n && n_col<m && vis[n_row][n_col]!=1 && board[n_row][n_col]==1){
                dfs(n_row,n_col,board,vis,n,m,drow,dcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(0,i,grid,vis,n,m,drow,dcol);
            }
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(n-1,i,grid,vis,n,m,drow,dcol);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,grid,vis,n,m,drow,dcol);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis,n,m,drow,dcol);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};