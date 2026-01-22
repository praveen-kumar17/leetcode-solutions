class Solution {
private:
    bool ispalindrome(string s){
        string s1=s;
        reverse(s1.begin(),s1.end());
        return s==s1;
    }
    void generate(string s,vector<vector<string>>& res,vector<string>& ans){
        if(s.length()==0){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(ispalindrome(part)){
                ans.push_back(part);
                generate(s.substr(i+1),res,ans);
                ans.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        generate(s,res,ans);
        return res;
    }
};