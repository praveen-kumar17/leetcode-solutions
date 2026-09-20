class Solution {
public:
    int reverseDegree(string s) {
        long long ans=0;
        for(int i=0;i<s.length();i++){
            int degree=s[i]-'a'+1;
            ans+=(27-degree)*(i+1);
        }
        return ans;
    }
};