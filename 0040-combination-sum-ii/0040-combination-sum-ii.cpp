class Solution {
private:
    void combination(vector<int>& candidates,int target,vector<vector<int>> &res,vector<int> &ans,int idx,int sum){
        if(sum==target){
            res.push_back(ans);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(sum+candidates[i]>target) break;

            ans.push_back(candidates[i]);
            combination(candidates,target,res,ans,i+1,sum+candidates[i]);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        combination(candidates,target,res,ans,0,0);
        return res;
    }
};