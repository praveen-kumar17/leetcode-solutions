class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int total=accumulate(cost.begin(),cost.end(),0);
        int moves=0;
        int i=n-1;
        while(i>=0){
            moves+=1;
            if(moves>2){
                total-=cost[i];
                moves=0;
            }
            i--;
        }
        return total;
    }
};