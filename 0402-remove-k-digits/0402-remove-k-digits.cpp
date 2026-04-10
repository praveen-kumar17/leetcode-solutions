class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
            while(k>0 && !st.empty()){
                st.pop();
                k--;
            }
            if(st.empty()){
                return "0";
            }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i=0;
        while(i<res.size() && res[i]=='0'){
            i++;

        }
        res=res.substr(i);
        return res.empty()? "0":res;
    }
};