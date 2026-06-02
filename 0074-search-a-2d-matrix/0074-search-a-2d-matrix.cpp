class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                int l=0,r=m-1;
                while(l<=r){
                    int p=l+(r-l)/2;
                    if(matrix[mid][p]==target) return true;
                    else if(matrix[mid][p]<target){
                        l=p+1;
                    }else{
                        r=p-1;
                    }
                }
                return false;
            }
            else if(target>matrix[mid][0]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};