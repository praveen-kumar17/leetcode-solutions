class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int l=0,max_len=0;
        for(int r=0;r<fruits.size();r++){
            freq[fruits[r]]++;
            if(freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0) freq.erase(fruits[l]);
                l++;
            }
            if(freq.size()<=2){
                max_len=max(max_len,r-l+1);
            }
        }
        return max_len;
    }
};