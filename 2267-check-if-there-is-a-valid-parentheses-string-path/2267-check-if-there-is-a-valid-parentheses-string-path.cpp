class Solution {
public:
    bool f(vector<vector<char>>& grid,int n,int m,int cnt,int i,int j,vector<vector<vector<int>>>& dp){
        if(i>=n || j>=m){
            return false;
        }
        if(grid[i][j]=='('){
            cnt++;
        }else{
            cnt--;
        }
        if(cnt<0){
            return false;
        }
        if(i==n-1 && j==m-1){
            return cnt==0;
        }
        if(dp[i][j][cnt]!=-1){
            return dp[i][j][cnt];
        }
        bool down=f(grid,n,m,cnt,i+1,j,dp);
        bool right=f(grid,n,m,cnt,i,j+1,dp);
        return dp[i][j][cnt]=down||right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int length=(n+m)-1;
        if(length%2==1){
            return false;
        }
        if(grid[0][0]==')' || grid[n-1][m-1]=='('){
            return false;
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(length+1,-1)));
        return f(grid,n,m,0,0,0,dp);
    }
};