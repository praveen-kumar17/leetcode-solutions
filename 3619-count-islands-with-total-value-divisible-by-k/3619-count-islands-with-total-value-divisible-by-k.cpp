class Solution {
public:
    vector<int> drow={-1,1,0,0};
    vector<int> dcol={0,0,-1,1};
    int dfs(int row,int col,vector<vector<bool>>& vis,vector<vector<int>>& grid,int n,int m,long long& sum){
        vis[row][col]=true;
        sum+=grid[row][col];
        for(int i=0;i<4;i++){
            int new_row=row+drow[i];
            int new_col=col+dcol[i];
            if(new_row<n && new_col<m && new_row>=0 && new_col>=0 && !vis[new_row][new_col] && grid[new_row][new_col]!=0){
                dfs(new_row,new_col,vis,grid,n,m,sum);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    long long sum=0;
                    dfs(i,j,vis,grid,n,m,sum);
                    if(sum%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};