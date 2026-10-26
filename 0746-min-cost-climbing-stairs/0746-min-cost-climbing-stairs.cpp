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
        vector<int> dp(n+1,-1);
        return min(f(cost,0,n,dp),f(cost,1,n,dp));
    }
};