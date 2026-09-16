class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int pivot=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1){
            return reverse(nums.begin(),nums.end());
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[pivot]){
                swap(nums[pivot],nums[i]);
                break;
            }
        }
        int i=pivot+1,j=n-1;
        while(i<j){
            swap(nums[i++],nums[j--]);
        }
        return ;
    }
};