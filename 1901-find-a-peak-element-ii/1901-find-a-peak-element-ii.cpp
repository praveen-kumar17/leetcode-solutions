class Solution {
public:
    int possible(vector<vector<int>>& nums,int p){
        int n=nums.size();
        int maxele=-1;
        int maxind=-1;
        for(int i=0;i<n;i++){
            if(nums[i][p]>maxele){
                maxele=nums[i][p];
                maxind=i;
            }
        }
        return maxind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxele=possible(mat,mid);
            int left=(mid-1>=0) ? mat[maxele][mid-1]:-1;
            int right=(mid+1<m) ? mat[maxele][mid+1]:-1;
            if(mat[maxele][mid]>left && mat[maxele][mid]>right){
                return{maxele,mid};
            }
            else if(mat[maxele][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {};
    }
};