class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int duplicate=-1;
        int missing=-1;
        vector<int> freq(n*n+1,0);
        for(auto& row:grid){
            for(int x:row){
                freq[x]++;
            }
        }
        for(int i=1;i<=n*n;i++){
            if(freq[i]==2){
                duplicate=i;
            }
            if(freq[i]==0){
                missing =i;
            }
        }
        return {duplicate,missing};
    }
};