class Solution {
public:
    bool possi(vector<int>& mat, int target){
        int n=mat.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mat[mid]==target){
                return true;
            }
            else if(mat[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n-1;
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && target<=matrix[i][m-1]){
                return possi(matrix[i],target);
            }
        }
        return false;
    }
};