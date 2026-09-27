class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int left_max=height[i];
        int right_max=height[n-1];
        int water=0;
        while(i<=j){
            if(left_max<right_max){
                left_max=max(left_max,height[i]);
                water+=left_max-height[i];
                i++;
            }else{
                right_max=max(right_max,height[j]);
                water+=right_max-height[j];
                j--;
            }
        }
        return water;
    }
};