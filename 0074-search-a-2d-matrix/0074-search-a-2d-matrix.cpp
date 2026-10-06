class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                int ll=0,hh=m-1;
                while(ll<=hh){
                    int mm=ll+(hh-ll)/2;
                    if(matrix[mid][mm]==target){
                        return true;
                    }else if(matrix[mid][mm]>target){
                        hh=mm-1;
                    }else{
                        ll=mm+1;
                    }
                }
                return false;
            }
            else if(matrix[mid][0]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
};