class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            int prize=prices[i]-cost;
            profit=max(profit,prize);
            cost=min(cost,prices[i]);
        }
        return profit;
    }
};