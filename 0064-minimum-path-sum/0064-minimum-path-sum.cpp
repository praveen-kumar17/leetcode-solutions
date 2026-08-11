class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else {
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up=dp[i][j]=grid[i][j] + dp[i-1][j];
                    if(j>0) left= dp[i][j]=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
    }
};