class Solution {
public:
    int f(int ind,int prev_ind,vector<int>& nums,int n){
        if(ind==n){
            return 0;
        }
        int length=f(ind+1,prev_ind,nums,n);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            length=max(length,1+f(ind+1,ind,nums,n));
        }

        return length;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int length=0+dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j]){
                    length=max(length,1+dp[i+1][i+1]);
                }
                dp[i][j+1]=length;
            }

        }
        return dp[0][0];
    }
};