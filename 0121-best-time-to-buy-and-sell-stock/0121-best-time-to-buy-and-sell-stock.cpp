class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int min_price=INT_MAX;
        for(int x:prices){
            min_price=min(x,min_price);
            max_profit=max(max_profit,x-min_price);
        }
        return max_profit;
    }
};