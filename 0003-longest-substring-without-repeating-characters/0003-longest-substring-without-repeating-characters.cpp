class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char> mpp;
        int cnt=0;
        int i=0;
        for(int j=0;j<n;j++){
            if(mpp.count(s[j])==0){
                mpp.insert(s[j]);
                cnt=max(cnt,j-i+1);
            }else{
                while(mpp.count(s[j])){
                    mpp.erase(s[i]);
                    i++;
                }
                mpp.insert(s[j]);
            }
        }
        return cnt;
    }
};