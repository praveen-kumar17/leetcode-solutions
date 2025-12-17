class Solution {
public:
    int checkingele(vector<int>& nums,int check,int threshold){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]+check-1)/check;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=*max_element(nums.begin(),nums.end());
        int low=1, high=maxi;
        int result=-1;
        while(low<=high){
            int mid=(low+high)/2;
                if(checkingele(nums,mid,threshold)){
                    result=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        return result;
    }
};