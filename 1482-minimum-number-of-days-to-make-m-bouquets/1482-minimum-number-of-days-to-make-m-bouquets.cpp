class Solution {
public:
    int ifpossible(vector<int>& nums,int day,int m,int k){
        int n=nums.size();
        int count=0;
        int bouquets=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=day){
                count++;
                if(count==k){
                    bouquets++;
                    count=0;
                }
            }
            else{
                count=0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        long long totalflowers=1LL*m*k;
        int n=nums.size();
        int result =-1;
        if(totalflowers>n) return -1;
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int low=mini, high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(ifpossible(nums,mid,m,k)){
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