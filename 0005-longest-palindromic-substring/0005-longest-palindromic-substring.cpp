class Solution {
public:
    string longestPalindrome(string s) {
       int n=s.length();
       string res="";
       int max_len=0;
       for(int i=0;i<n;i++){
        int left=i,right=i;
        while((left>=0 && right<n) && s[left]==s[right]){
            if((right-left+1)>max_len){
               res=s.substr(left,(right-left+1));
               max_len=right-left+1;
               }
               left-=1;
               right+=1;
            }
        left=i,right=i+1;
        while((left>=0 && right<n) && s[left]==s[right]){
            if((right-left+1)>max_len){
                res=s.substr(left,(right-left+1));
                max_len=right-left+1;
                }
            left-=1;
            right+=1;
            }
        }
        return res;
    }
};