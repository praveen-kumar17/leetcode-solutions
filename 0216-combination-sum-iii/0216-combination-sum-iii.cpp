class Solution {
private:
    void generate(int idx,vector<vector<int>>& res,vector<int>& ans,int k,int n){
        if(n==0 && ans.size()==k){
            res.push_back(ans);
            return;
        }
        if(ans.size()>k || n<0){
            return;
        }
        for(int i=idx;i<=9;i++){
            if(i<=n){
                ans.push_back(i);
                generate(i+1,res,ans,k,n-i);
                ans.pop_back();
            }
            else{
                break;
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ans;
        generate(1,res,ans,k,n);
        return res;
    }
};