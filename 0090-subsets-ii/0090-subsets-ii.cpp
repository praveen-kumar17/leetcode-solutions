class Solution {
private:
    void combination(vector<int>& nums,vector<vector<int>>& res,vector<int>& ans,int idx){
        res.push_back(ans);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
            combination(nums,res,ans,i+1);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        combination(nums,res,ans,0);
        return res;
    }
};