class Solution {
public:
    int f(vector<int>& nums,int ind,int buy,int n,vector<vector<int>>& dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int profit;
        if(buy==0){
            profit=max(f(nums,ind+1,0,n,dp),-nums[ind]+f(nums,ind+1,1,n,dp));
        }
        if(buy==1){
            profit=max(f(nums,ind+1,1,n,dp),nums[ind]+f(nums,ind+2,0,n,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    dp[ind][buy]=max(dp[ind+1][0],-prices[ind]+dp[ind+1][1]);
                }
                if(buy==1){
                    dp[ind][buy]=max(dp[ind+1][1],prices[ind]+ dp[ind+2][0]);
                }
            }
        }
        return dp[0][0];
    }
};