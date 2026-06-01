class Solution {
public:
    int findsubarray(vector<int>& nums,int k,int maxi){
        int subarrays=1;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=maxi){
                sum+=nums[i];
            }else{
                subarrays++;
                sum=nums[i];
            }
        }
        return subarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int subarrays=findsubarray(nums,k,mid);
            if(subarrays<=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};