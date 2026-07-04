class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1=s.length();
        int l2=t.length();
        if(l1!=l2) return false;
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
        for(int i=0;i<l1;i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }
        if(mpp1==mpp2) return true;
        return false;
    }
};