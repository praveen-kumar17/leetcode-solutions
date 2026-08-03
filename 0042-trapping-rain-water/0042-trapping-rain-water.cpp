class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int lmax=height[l],rmax=height[r];
        int ans=0;
        while(l<r){
            if(lmax<rmax){
                l++;
                lmax=max(lmax,height[l]);
                ans+=lmax-height[l];
            }else{
                r--;
                rmax=max(rmax,height[r]);
                ans+=rmax-height[r];
            }
        }
        return ans;
    }
};