class Solution {
public:
    void dfs(vector<vector<char>>& board,int row,int col ,int n ,int m,vector<vector<bool>>& vis){
        vis[row][col]=true;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int new_row=row+drow[i];
            int new_col=col+dcol[i];
            if(new_row>=0 && new_col>=0 && new_row<n && new_col<m && !vis[new_row][new_col] && board[new_row][new_col]=='O'){
                dfs(board,new_row,new_col,n,m,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(board,0,i,n,m,vis);
            }
            if(board[n-1][i]=='O' && !vis[n-1][i]){
                dfs(board,n-1,i,n,m,vis);
            }
        }
        for(int j=0;j<n;j++){
            if(board[j][0]=='O' && !vis[j][0]){
                dfs(board,j,0,n,m,vis);
            }
            if(board[j][m-1]=='O' && !vis[j][m-1]){
                dfs(board,j,m-1,n,m,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};