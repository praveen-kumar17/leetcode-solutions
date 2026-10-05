class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int x:nums){
            ans^=x;
        }
        return ans;
    }
};