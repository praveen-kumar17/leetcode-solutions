class Solution {
private:
    void generate(vector<string>& res,int idx,string alpha[],string digits,string ans){
        int n=digits.size();
        if(idx==digits.size()){
            res.push_back(ans);
            return;
        }
        int digit=digits[idx]-'0';
        for(int i=0;i<alpha[digit].size();i++){
            generate(res,idx+1,alpha,digits,ans+alpha[digit][i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string  alpha[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string ans="";
        generate(res,0,alpha,digits,ans);
        return res;

    }
};