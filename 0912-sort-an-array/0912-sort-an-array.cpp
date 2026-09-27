class Solution {
public:
    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int> temp;
        int l=low,r=mid+1;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l]);
                l++;
            }else{
                temp.push_back(nums[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(nums[r]);
            r++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    void merge_sort(vector<int>& nums,int low,int high){
        if(low>=high){
            return;
        }
        int mid=low+(high-low)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};