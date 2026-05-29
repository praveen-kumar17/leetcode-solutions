class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int min_el=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            while(nums[i]>0){
                int digit=nums[i]%10;
                sum+=digit;
                nums[i]/=10;
            }
            min_el=min(min_el,sum);
        }
        return min_el;
    }
};