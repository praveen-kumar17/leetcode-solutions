class Solution {
public:
    int f(vector<int>& nums){
        int n = nums.size();

        int prev = 0;
        int prevOfPrev = 0;
        int curr = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                curr = nums[i]; // max(0, nums[i] + 0)
            else if (i == n - 2)
                curr = max(prev, nums[i]); // max(prev, nums[i] + 0);
            else
                curr = max(prev, nums[i] + prevOfPrev);

            prevOfPrev = prev;
            prev = curr;
        }

        return curr;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>nums1;
        vector<int>nums2;
        for(int i=0;i<n;i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
        }
        return max(f(nums1),f(nums2));
    }
};