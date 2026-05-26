class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long total=accumulate(nums.begin(),nums.end(),0);
        long long prefix_sum=0;
        for(int i=0;i<nums.size();i++){
            long long suffix_sum=total-prefix_sum-nums[i];
            if(prefix_sum==suffix_sum){
                return i;
            }
            prefix_sum+=nums[i];
        }
        return -1;
    }
};