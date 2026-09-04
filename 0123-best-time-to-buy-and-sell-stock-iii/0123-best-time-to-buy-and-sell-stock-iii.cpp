class Solution {
public:
    int f(vector<int>& nums,int ind,int buy,int trans,vector<vector<vector<int>>>& dp){
        if(ind==nums.size() || trans==0){
            return 0;
        }
        if(dp[ind][buy][trans]!=-1){
            return dp[ind][buy][trans];
        }
        int profit;
        if(buy==0){
            profit=max(0+f(nums,ind+1,0,trans,dp),-nums[ind]+f(nums,ind+1,1,trans,dp));
        }if(buy==1){
            profit=max(0+f(nums,ind+1,1,trans,dp),nums[ind]+f(nums,ind+1,0,trans-1,dp));
        }
        return dp[ind][buy][trans]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind =n-1;ind >=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int trans=1;trans<=2;trans++){
                    if(buy==0){
                        dp[ind][buy][trans]=max(0+dp[ind+1][0][trans],-prices[ind]+dp[ind+1][1][trans]);
                    }
                    if(buy==1){
                        dp[ind][buy][trans]=max(0+dp[ind+1][1][trans],prices[ind]+dp[ind+1][0][trans-1]);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};