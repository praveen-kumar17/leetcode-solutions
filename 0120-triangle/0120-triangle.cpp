class Solution {
public:
    long long f(int row,int col,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(row==n-1){
            return triangle[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        long long down=f(row+1,col,n,triangle,dp);
        long long side=f(row+1,col+1,n,triangle,dp);
        return dp[row][col]=triangle[row][col]+min(down,side);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[n][n];
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i==n-1){
                    dp[i][j]=triangle[i][j];
                }
                else{
                    int  up=triangle[i][j]+dp[i+1][j];
                    int  side=triangle[i][j]+dp[i+1][j+1];
                        dp[i][j]=min(up,side);
                }
            }
        }
        return dp[0][0];
    }
};