class Solution {
public:
    int f(int ind,int n,vector<int>& nums,vector<int>& dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int take=nums[ind]+f(ind+2,n,nums,dp);
        int nottake=f(ind+1,n,nums,dp);
        return dp[ind]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            int take=nums[i]+dp[i+2];
            int nottake=dp[i+1];
            dp[i]=max(take,nottake);
        }
        return max(dp[0],dp[1]);
    }
};