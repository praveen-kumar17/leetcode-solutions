class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev;
        for(int i=n-1;i>=0;i--){
            vector<int> curr(i+1);
            for(int j=i;j>=0;j--){
                if(i==n-1){
                    curr[j]=triangle[i][j];
                }
                else{
                    int  up=triangle[i][j]+prev[j];
                    int  side=triangle[i][j]+prev[j+1];
                    curr[j]=min(up,side);
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};