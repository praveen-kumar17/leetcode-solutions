class Solution {
private:
    bool issafe(vector<string>& board,int n,int rows,int col){
        for(int i=0;i<rows;i++){
            if(board[rows][i]=='Q'){
                return false;
            }
        }
        for(int j=0;j<rows;j++){
            if(board[j][col]=='Q'){
                return false;
            }
        }
        for(int i=rows,j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=rows,j=col; i>=0 && j<n; i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;

    }
    void generate(vector<vector<string>>& ans,vector<string>& board,int n,int rows){
        if(rows==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(board,n,rows,i)){
                board[rows][i]='Q';
                generate(ans,board,n,rows+1);
                board[rows][i]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        generate(ans,board,n,0);
        return ans;
    }
};