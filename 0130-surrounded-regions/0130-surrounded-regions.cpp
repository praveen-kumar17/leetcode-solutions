class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis,int n,int m,int drow[],int dcol[]){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int n_row=row+drow[i];
            int n_col=col+dcol[i];
            if(n_row>=0 && n_col>=0 && n_row<n && n_col<m && vis[n_row][n_col]!=1 && board[n_row][n_col]=='O'){
                dfs(n_row,n_col,board,vis,n,m,drow,dcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(0,i,board,vis,n,m,drow,dcol);
            }
            if(board[n-1][i]=='O' && !vis[n-1][i]){
                dfs(n-1,i,board,vis,n,m,drow,dcol);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis,n,m,drow,dcol);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis,n,m,drow,dcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};