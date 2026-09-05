class Solution {
public:
    int f(vector<int>& nums,int ind,int buy,int k,int n,vector<vector<vector<int>>>& dp){
        if(ind==n || k==0){
            return 0;
        }
        if(dp[ind][buy][k]!=-1){
            return dp[ind][buy][k];;
        }
        int profit;
        if(buy==0){
            profit= max(f(nums,ind+1,0,k,n,dp),-nums[ind]+f(nums,ind+1,1,k,n,dp));
        }
        if(buy==1){
            profit=max(f(nums,ind+1,1,k,n,dp),nums[ind]+f(nums,ind+1,0,k-1,n,dp));
        }
        return dp[ind][buy][k]= profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(prices,0,0,k,n,dp);
    }
};