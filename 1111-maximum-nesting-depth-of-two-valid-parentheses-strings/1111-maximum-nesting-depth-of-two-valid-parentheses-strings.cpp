class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.length();
        vector<int> res;
        int depth=0;
        for(char c: seq){
            if(c=='('){
                depth++;
                if(depth%2!=0){
                    res.push_back(0);
                }else{
                    res.push_back(1);
                }
            }else{
                if(depth%2!=0){
                    res.push_back(0);
                }else{
                    res.push_back(1);
                }
                depth--;
            }
        }
        return res;
    }
};