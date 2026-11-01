class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        string word="";
        for(char c: s){
            if(c!=' '){
                word+=c;
            }else{
                if(!word.empty()){
                    reverse(word.begin(),word.end());
                    if(!ans.empty()){
                    ans+=' ';
                    }
                    ans+=word;
                    word="";
                }
            }
        }
        if(!word.empty()){
            reverse(word.begin(),word.end());
            if(!ans.empty()){
                ans+=' ';
            }
            ans+=word;
        }
        return ans;
        
    }
};