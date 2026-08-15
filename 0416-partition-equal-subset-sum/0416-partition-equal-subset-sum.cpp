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
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=target){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool notTake=dp[i-1][j];
                bool take=false;
                if(j>=nums[i]){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=notTake | take;
            }
        }
        return dp[n-1][target];
    }
};