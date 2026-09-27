class Solution {
public:
    int merge(vector<int>& nums,int low,int mid,int high){
        vector<int> temp;
        int l=low,r=mid+1;
        int cnt=0;
        for (int l = low; l <= mid; l++) {
            while (r <= high && (long long)nums[l] > 2LL * nums[r]) {
                r++;
            }
            cnt+=r - (mid + 1);
        }
        l=low;
        r=mid+1;
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
        return cnt;
    }
    int merge_sort(vector<int>& nums,int low,int high){
        if(low>=high){
            return 0;
        }
        int cnt=0;
        int mid=low+(high-low)/2;
        cnt+=merge_sort(nums,low,mid);
        cnt+=merge_sort(nums,mid+1,high);
        cnt+=merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
};