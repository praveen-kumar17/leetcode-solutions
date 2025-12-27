class Solution {
public:
    int maxDepth(string s) {
        int value=0;
        int max_value=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                value++;
                max_value=max(max_value,value);
            } else if(s[i]==')'){
                value--;
            }
        }
        return max_value;
    }
};