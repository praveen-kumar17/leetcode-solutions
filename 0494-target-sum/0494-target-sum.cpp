class Solution {
public:
    int find(vector<int>& nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }
    int f(int ind,vector<int>& nums,int diff,vector<vector<int>>& dp){
        if(ind==0){
            if(diff==0 && nums[0]==0){
                return 2;
            }
            if(diff==0 || nums[0]==diff){
                return 1;
            }
            return 0;
        }
        if(dp[ind][diff]!=-1){
            return dp[ind][diff];
        }
        int notpick=f(ind-1,nums,diff,dp);
        int pick=0;
        if(diff>=nums[ind]){
             pick=f(ind-1,nums,diff-nums[ind],dp);
        }
        return dp[ind][diff]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total_sum=find(nums);
        int diff=(total_sum-target)/2;
        if(total_sum-target < 0 || (total_sum-target)%2!=0){
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(diff+1,-1));
        return f(n-1,nums,diff,dp);
    }
};