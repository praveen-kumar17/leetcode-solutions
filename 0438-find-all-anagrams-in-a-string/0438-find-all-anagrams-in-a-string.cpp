class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        int cnt=m,l=0;
        vector<int> ans;
        unordered_map<char,int> mpp;
        for(int i=0;i<m;i++){
            mpp[p[i]]++;
        }
        for(int r=0;r<n;r++){
            if(mpp[s[r]]>0){
                cnt--;
            }
            mpp[s[r]]--;
            if(r-l+1==m){
                if(cnt==0){
                    ans.push_back(l);
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    cnt++;
                }
            l++;
            }
        }
        return ans;
    }
};