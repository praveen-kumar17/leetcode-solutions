class Solution {
private:
    void combination(vector<int>& candidates,int target,vector<vector<int>> &res,vector<int> &ans,int idx,int sum){
        if(sum==target){
            res.push_back(ans);
            return;
        }
        if(idx==candidates.size() || sum>target){
            return;
        }
        ans.push_back(candidates[idx]);
        combination(candidates,target,res,ans,idx,sum+candidates[idx]);
        ans.pop_back();
        combination(candidates,target,res,ans,idx+1,sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        combination(candidates,target,res,ans,0,0);
        return res;
    }
};