class Solution {
public:
    int f(vector<int>& nums){
        int maxi=INT_MIN;
        for(int x: nums){
            maxi=max(maxi,x);
        }
        return maxi;
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_el=f(candies);
        int n=candies.size();
        vector<bool> ans(n,false);
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=max_el){
                ans[i]=true;
            }
        }
        return ans;

    }
};