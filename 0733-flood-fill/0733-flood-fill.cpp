class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>& image,int color,int intial_col,int drow[],int dcol[]){
        image[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int row=sr+drow[i];
            int col=sc+dcol[i];
            if(row>=0 && col>=0 && row<n && col<m && image[row][col]==intial_col){
                dfs(row,col,image,color,intial_col,drow,dcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int intial_col=image[sr][sc];
        if(intial_col==color){
            return image;
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        dfs(sr,sc,image,color,intial_col,drow,dcol);
        return image;
    }
};