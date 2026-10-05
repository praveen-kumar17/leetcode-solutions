class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> freq(n*n+1,0);
        for(auto& x: grid){
            for(int it:x){
                freq[it]++;
            }
        }
        int missing=-1;
        int repeated=-1;
        for(int i=1;i<freq.size();i++){
            if(freq[i]==0){
                missing = i;
            }
            if(freq[i]==2){
                repeated=i;
            }
        }
        return {repeated,missing};
    }
};