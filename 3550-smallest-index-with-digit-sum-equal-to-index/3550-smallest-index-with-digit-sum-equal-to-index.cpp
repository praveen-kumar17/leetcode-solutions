class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int num=nums[i];
            while(num>0){
                int digit=num%10;
                sum+=digit;
                num/=10;
            }
            if(sum==i){
                res=min(res,i);
            }
        }
        return res==INT_MAX ? -1:res;
    }
};