class Solution {
public:
    bool dfs(int idx,vector<int>& nums,vector<int>& sides,int target){
        if(idx==nums.size()){
            return sides[0]==target && sides[1]==target && sides[2]==target && sides[3]==target;
        }
        for(int i=0;i<4;i++){
            if(sides[i]+nums[idx]>target){
                continue;
            }
            sides[i]+=nums[idx];
            if(dfs(idx+1,nums,sides,target)) return true;
            sides[i]-=nums[idx];
            if(sides[i]==0) break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int total_sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(total_sum%4!=0){
            return false;
        }
        int target=total_sum/4;
        vector<int> sides(4,0);
        sort(matchsticks.rbegin(),matchsticks.rend());
        return dfs(0,matchsticks,sides,target);
    }
};