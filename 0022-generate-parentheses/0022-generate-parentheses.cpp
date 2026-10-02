class Solution {
public:
    void solve(int open,int closed,string curr,vector<string>& res){
        if(open==0 && closed==0){
            res.push_back(curr);
            return;
        }
        if(open>0) solve(open-1,closed,curr+'(',res);
        if(closed>open) solve(open,closed-1,curr+')',res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(n,n,"",res);
        return res;
    }
};