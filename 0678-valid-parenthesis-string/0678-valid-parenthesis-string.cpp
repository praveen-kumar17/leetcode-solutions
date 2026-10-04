class Solution {
public:
    bool f(string s ,int ind,int cnt,int n,vector<vector<int>>& dp){
        if(cnt<0){
            return false;
        }
        if(ind==n){
            return cnt==0;
        }
        if(dp[ind][cnt]!=-1){
            return dp[ind][cnt];
        }
        if(s[ind]=='('){
            return dp[ind][cnt]=f(s,ind+1,cnt+1,n,dp);
        }
        if(s[ind]==')'){
            return dp[ind][cnt]=f(s,ind+1,cnt-1,n,dp);
        }
        return dp[ind][cnt]=f(s,ind+1,cnt,n,dp)|| f(s,ind+1,cnt+1,n,dp) || f(s,ind+1,cnt-1,n,dp);
    }
    bool checkValidString(string s) {
        int n=s.length();
        if(n==1 && s[0]!='*'){
            return false;
        }
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(s,0,0,n,dp);
    }
};