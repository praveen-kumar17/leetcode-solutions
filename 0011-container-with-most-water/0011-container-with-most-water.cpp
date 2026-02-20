class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int max_water=INT_MIN;
        int ans=INT_MIN;
        while(i<j){
            int start=height[i];
            int end=height[j];
            ans=min(start,end)*(j-i);
            max_water=max(max_water,ans);
            if(start<end){
                i++;
            }else{
                j--;
            }
        }
        return max_water;
    }
};