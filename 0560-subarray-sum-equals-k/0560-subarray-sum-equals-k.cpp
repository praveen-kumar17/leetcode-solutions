class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int prefix=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int need=prefix-k;
            if(mpp.count(need)){
                ans+=mpp[need];
            }
            mpp[prefix]++;
        }
        return ans;

    }
};