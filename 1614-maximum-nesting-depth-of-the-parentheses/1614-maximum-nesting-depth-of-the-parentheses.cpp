class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        stack<char> st;
        int max_cnt=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
            }
            max_cnt=max(cnt,max_cnt);
        }
        return max_cnt;
    }
};