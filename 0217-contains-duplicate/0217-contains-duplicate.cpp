class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mpp;
        for(int x:nums){
            if(mpp.find(x)!=mpp.end()){
            return true;
            }
        mpp.insert(x);
        }
        return false;
    }
};