class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0;
        int max_len=0;
        unordered_set<char> mpp;
        for(int right=0;right<n;right++){
            if(mpp.count(s[right])==0){
                max_len=max(max_len,(right-left)+1);
                mpp.insert(s[right]);
            }else{
                while(mpp.count(s[right])){
                    mpp.erase(s[left]);
                    left++;
                }
                mpp.insert(s[right]);
            }
        }
        return max_len;
    }
};