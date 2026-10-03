class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0,closed=0,ans=0;
        for(char c:s){
            if(c=='('){
                open++;
            }else{
                closed++;
            }
            if(open==closed){
                ans=max(ans,2*closed);
            }
            if(closed>open){
                closed=open=0;
            }
        }
        closed=open=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')'){
                closed++;
            }else{
                open++;
            }
            if(open==closed){
                ans=max(ans,2*open);
            }
            if(open>closed){
                closed=open=0;
            }
        }
        return ans;
    }
};