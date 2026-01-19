class Solution {
public:
    void generate(int n,int open,int closed,string curr,vector<string>& res){
        if(curr.length()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n) generate(n,open+1,closed,curr+'(',res);
        if(closed<open) generate(n,open,closed+1,curr+')',res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,0,0,"",res);
        return res;
    }
};