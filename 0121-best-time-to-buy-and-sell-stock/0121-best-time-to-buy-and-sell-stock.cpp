class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price=0;
        int min_price=INT_MAX;
        for(int x:prices){
            min_price=min(min_price,x);
            price=max(price,x-min_price);
        }
        return price;
        
    }
};