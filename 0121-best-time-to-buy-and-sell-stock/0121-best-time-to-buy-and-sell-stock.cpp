class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX;
        int profit=0;
        for(int x:prices){
            min_price=min(x,min_price);
            profit=max(profit,x-min_price);
        }
        return profit;
    }
};