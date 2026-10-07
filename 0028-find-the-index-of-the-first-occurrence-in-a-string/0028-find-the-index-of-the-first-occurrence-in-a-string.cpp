class Solution {
public:
void compute(string pat,vector<int>& lps,int m){
        int len=0;
        int i=1;
        while(i<m){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    int strStr(string txt, string pat) {
        int m=pat.size();
        int n=txt.size();
        vector<int>lps(m,0);
        int ans=-1;
        compute(pat,lps,m);
        int i=0,j=0;
        while(i<n){
            if(txt[i]==pat[j]){
                i++;
                j++;
            }
            if(j==m){
                if(ans!=-1){
                    return ans;
                }
                else{
                    ans=i-m;
                    //j=lps[j-1];
                }
            }
            else if(txt[i]!=pat[j]){
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return ans;
    }
};