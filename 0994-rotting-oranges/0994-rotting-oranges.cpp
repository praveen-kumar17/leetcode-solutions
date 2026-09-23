class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int max_time=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            max_time=max(max_time,time);
            for(int i=0;i<4;i++){
                int new_row=row+drow[i];
                int new_col=col+dcol[i];
                if(new_row>=0 && new_col>=0 && new_row<n && new_col<m && !vis[new_row][new_col] && grid[new_row][new_col]==1){
                    vis[new_row][new_col]=2;
                    q.push({{new_row,new_col},time+1});
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return max_time;

    }
};