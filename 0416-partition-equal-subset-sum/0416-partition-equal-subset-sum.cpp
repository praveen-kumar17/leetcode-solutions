class Solution {
public:
    int find(vector<int>& nums,int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return sum;
    }
    bool f(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0){
            return true;
        }
        if(ind==0){
            return target==nums[0];
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        bool notTake=f(ind-1,target,nums,dp);
        bool take=false;
        if(target>=nums[ind]){
            take=f(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=notTake | take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total_sum=find(nums,n);
        if(total_sum%2!=0){
            return false;
        }
        int target=total_sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);
    }
};