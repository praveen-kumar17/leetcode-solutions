class Solution {
public:
    int fl(vector<int>& piles){
        int l=INT_MIN;
        for(int x:piles){
            l=max(l,x);
        }
        return l;
    }
    long long find(int mid,vector<int>& piles){
        long long cnt=0;
        for(int x: piles){
            cnt+=ceil((double)x/(double)mid);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=fl(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long ans=find(mid,piles);
            if(ans<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        return low;
    }
};