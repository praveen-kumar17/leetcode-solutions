class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        double max_avg=INT_MIN;
        double sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            if(j-i+1==k){
                double avg=sum/k;
                max_avg=max(max_avg,avg);
                sum-=nums[i];
                i++;
            }
        }
        return max_avg;
    }
};