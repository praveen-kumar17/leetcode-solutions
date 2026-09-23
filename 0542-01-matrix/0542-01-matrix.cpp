class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            ans[row][col]=dis;
            for(int i=0;i<4;i++){
                int new_row=row+drow[i];
                int new_col=col+dcol[i];
                if(new_row>=0 && new_col>=0 && new_col<m && new_row<n && vis[new_row][new_col]!=1 && mat[new_row][new_col]==1){
                    vis[new_row][new_col]=1;
                    q.push({{new_row,new_col},dis+1});
                }
            }
        }
        return ans;
    }
};