class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> mpp;
        vector<vector<int>> res;
        for(int i=0;i<(1<<n);i++){
            vector<int> ans;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    ans.push_back(nums[j]);
                }
            }
            mpp.insert(ans);
        }
        for(auto& it: mpp){
            res.push_back(it);
        }
        return res;
    }
};