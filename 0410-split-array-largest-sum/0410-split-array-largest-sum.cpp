class Solution {
public:
    int ifpossible(vector<int>& nums,int k,int maxi){
        int n=nums.size();
        long long sum=0;
        int arrays =1;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=maxi){
                sum+=nums[i];
            }
            else{
                arrays++;
                sum=nums[i];
            }
        }
        return arrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int arrays=ifpossible(nums,k,mid);
            if(arrays<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};