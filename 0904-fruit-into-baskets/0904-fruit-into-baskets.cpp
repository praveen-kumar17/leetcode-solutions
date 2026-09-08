class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> mpp;
        int max_len=0;
        int i=0;
        for(int j=0;j<n;j++){
            mpp[fruits[j]]++;
            while(mpp.size()>2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0){
                    mpp.erase(fruits[i]);
                }
                i++;
            }
            max_len=max(max_len,j-i+1);
        }
        return max_len;
    }
};