class Solution {
public:
    int findfirst(vector<int>& nums,int target){
        int n=nums.size();
        int low=0,high=n-1,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    int findsecond(vector<int>& nums,int target){
        int n=nums.size();
        int low=0,high=n-1,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findfirst(nums,target);
        if(first==-1) return {-1,-1};
        int second=findsecond(nums,target);
        return {first,second};
    }
};