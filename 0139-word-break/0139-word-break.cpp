class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,false);
        dp[0]=true;
        int max_len=0;
        for(const string& word:wordDict){
                max_len=max(max_len,(int)word.size());
            }
        for(int i=1;i<=n;i++){
            for(int j=max(0,i-max_len);j<i;j++){
                if(dp[j] && dict.find(s.substr(j,i-j))!=dict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};