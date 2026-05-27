class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> mpp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val)!=mpp.end()){
            return false;
        }else{
            nums.push_back(val);
            mpp[val]=nums.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(mpp.find(val)==mpp.end()){
            return false;
        }
        int index=mpp[val];
        int last_el=nums.back();
        nums[index]=last_el;
        mpp[last_el]=index;
        nums.pop_back();
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        int random=rand()% nums.size();
        return nums[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */