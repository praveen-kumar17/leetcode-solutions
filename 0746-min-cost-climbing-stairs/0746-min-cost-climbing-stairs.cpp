class Solution {
public:
    int f(vector<int>& cost,int ind,int n,vector<int>& dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int take=cost[ind]+f(cost,ind+1,n,dp);
        int nottake=cost[ind]+f(cost,ind+2,n,dp);
        return dp[ind]=min(take,nottake);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+2);
        for(int i=n-1;i>=0;i--){
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};