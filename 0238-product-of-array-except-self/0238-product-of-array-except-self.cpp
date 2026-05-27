class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> prefix_p(n,1);
        for(int i=1;i<n;i++){
            prefix_p[i]=prefix_p[i-1]*nums[i-1];
        }
        vector<int> suffix_p(n,1);
        for(int i=n-2;i>=0;i--){
            suffix_p[i]=suffix_p[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=prefix_p[i]*suffix_p[i];
        }
        return ans;
    }
};