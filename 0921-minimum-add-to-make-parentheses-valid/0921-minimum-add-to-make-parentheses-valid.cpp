class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for(char c: s){
            if(c=='('){
                st.push(c);
            }
            else{
                if(st.empty() || st.top()==')'){
                    st.push(c);
                }
                else{
                    st.pop();
                }
            }
        }
        return st.size();
    }
};