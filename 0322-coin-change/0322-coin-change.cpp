class Solution {
public:
    int f(int ind,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }
        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            return 1e9;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int nottake=f(ind-1,coins,amount,dp);
        int take=1e9;
        if(coins[ind]<=amount){
            take=1+f(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount]=min(nottake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int target = 0; target <= amount; target++) {
            if(target % coins[0] == 0) {
                dp[0][target] = target / coins[0];
            }
            else {
                dp[0][target] = 1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int nottake=dp[i-1][j];
                int take=1e9;
                if(coins[i]<=j){
                   take=1+dp[i][j-coins[i]];
          
                }
            dp[i][j]=min(take,nottake);
            }
        }
        if(dp[n-1][amount]>=1e9){
            return -1;
        }
        return dp[n-1][amount];
    }
};