class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long max_diff=INT_MIN;
        vector<long long > freq(1e5+1,0);
        for(int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            freq[diff]++;
        }
        long long K=k1+k2;
        for(int i=1e5; i>0 && K>0 ;i--){
            int deletions=min(K,freq[i]);
            freq[i]-=deletions;
            freq[i-1]+=deletions;
            K-=deletions;
        }
        long long res=0;
        for(int i=1;i<=1e5;i++){
            res+=(freq[i]*i*i);
        }
        return res;
    }
};