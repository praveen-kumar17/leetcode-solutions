class Solution {
public:
    string minWindow(string s, string t) {
        int m=t.length();
        int n=s.length();
        int start=-1,l=0,r=0;
        int cnt=0;
        int min_length=INT_MAX;
        unordered_map<char,int> mpp;
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        while(r<n){
            if(mpp[s[r]]>0){
                cnt++;
            }
            mpp[s[r]]--;
            while(cnt==m){
                if(r-l+1<min_length){
                    min_length=r-l+1;
                    start=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        
        }
        return (start==-1 ? "":s.substr(start,min_length));
    }
};