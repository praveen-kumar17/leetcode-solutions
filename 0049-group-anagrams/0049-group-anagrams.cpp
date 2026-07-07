class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto& x:strs){
            string s=x;
            sort(s.begin(),s.end());
            mpp[s].push_back(x);
        }
        vector<vector<string>> res;
        for(auto& it:mpp){
            res.push_back(it.second);
        }
        return res;
    }
};