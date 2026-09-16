class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool first_row=false;
        bool first_col=false;
        //row
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0){
                first_row=true;
            }
        }
        // col
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                first_col=true;
            }
        }
        //if any zero occurs make its first rowth and columth ele to zero
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //if any element zero in first row||col make that ele zero
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        //first row zeroes if 
        if(first_row){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        //first col zeroes if 
        if(first_col){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        return;
    }
};