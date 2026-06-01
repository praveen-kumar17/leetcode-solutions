class Solution {
public:
    int findmax(vector<int>& bloomDay){
        int maxi=INT_MIN;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,bloomDay[i]);
        }
        return maxi;
    }
    int find(vector<int>& bloomDay, int k, int days){
    int cnt = 0, bouquets = 0;

    for(int i = 0; i < bloomDay.size(); i++){
        if(bloomDay[i] <= days){
            cnt++;
            if(cnt == k){
                bouquets++;
                cnt = 0;
            }
        }else{
            cnt = 0;
        }
    }
    return bouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k> bloomDay.size()) return -1;
        int low=1,high=findmax(bloomDay);
        while(low<=high){
            int mid=low+(high-low)/2;
            int bloomed=find(bloomDay,k,mid);
            if(bloomed>=m){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};