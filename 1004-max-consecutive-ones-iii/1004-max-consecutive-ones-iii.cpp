class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,zeroes=0,max_len=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0) zeroes++;
            if(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            if(zeroes<=k){
                max_len=max(max_len,r-l+1);
            }
        }
        return max_len;
        
    }
};