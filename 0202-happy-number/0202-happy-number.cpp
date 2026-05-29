class Solution {
public:
    int nextnumber(int n){
        int out=0;
        while(n>0){
           int digit=n%10;
           out+=digit*digit;
           n/=10;
        }
        return out;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(seen.find(n)==seen.end()){
            seen.insert(n);
            n=nextnumber(n);
            if(n==1){
                return true;
            }
        }
        return false;
    }
};