class Solution {
public:
    int checkin(vector<int>& weights,int capacity){
        int n=weights.size();
        int load=0;
        int days=1;
        for(int x:weights){
            if(load+x>capacity){
                days++;
                load=x;
            }
            else{
                load+=x;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mini=*max_element(weights.begin(),weights.end());
        int maxi=accumulate(weights.begin(),weights.end(),0);
        int low=mini,high=maxi;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            int needed=checkin(weights,mid);
            if(needed<=days){
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