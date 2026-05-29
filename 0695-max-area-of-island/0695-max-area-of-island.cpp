class Solution {
public:
    int isit(vector<vector<int>> & grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) return 0;
        grid[i][j]=2;
        return 1 + isit(grid,i+1,j) + isit(grid,i-1,j) + isit(grid,i,j+1) + isit(grid,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int max_area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=isit(grid,i,j);
                    max_area=max(max_area,area);
                }
            }
        }
        return max_area;
    }
};