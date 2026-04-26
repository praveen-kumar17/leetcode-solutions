class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        int jumps=0;
        int current=0;
        int max_reach=0;
        for(int i=0;i<n;++i){
            max_reach=max(max_reach,i+nums[i]);
            if(i==current){
                ++jumps;
                current=max_reach;
                if(current>=n-1) break;
            }
        }
        return jumps;
    }
};