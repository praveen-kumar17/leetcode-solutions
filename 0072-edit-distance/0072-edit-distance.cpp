class Solution {
public:
    int f(string word1,int n,string word2,int m,vector<vector<int>>& dp){
        if(m==0){
            return n;
        }
        if(n==0){
            return m;
        }
        if(word1[n-1]==word2[m-1]){
            return f(word1,n-1,word2,m-1,dp);
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        return dp[n][m]=min({f(word1,n-1,word2,m,dp)+1,f(word1,n,word2,m-1,dp)+1,f(word1,n-1,word2,m-1,dp)+1});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(word1,n,word2,m,dp);
    }
};