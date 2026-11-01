class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_el=*min_element(nums.begin(),nums.end());
        int moves=0;
        for(int x: nums){
            moves+=x-min_el;
        }
        return moves;
    }
};