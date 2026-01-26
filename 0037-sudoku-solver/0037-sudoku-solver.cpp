class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,char dig){
        for(int i=0;i<9;i++){
            if(board[row][i]==dig) return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==dig) return false;
        }
        int rows=(row/3)*3;
        int coll=(col/3)*3;
        for(int i=rows;i<=rows+2;i++){
            for(int j=coll;j<=coll+2;j++){
                if(board[i][j]==dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool generate(vector<vector<char>>& board,int rows,int col){
        if(rows==9){
            return true;
        }

        int nextrow=rows, nextcol=col+1;
        if(nextcol==9){
            nextrow=rows+1;
            nextcol=0;
        }
        if(board[rows][col]!='.'){
            return generate(board,nextrow,nextcol);
        }
        for(char  i='1';i<='9';i++){
            if(issafe(board,rows,col,i)){
                board[rows][col]=i;
                if(generate(board,nextrow,nextcol)){
                    return true;
                }
                board[rows][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        generate(board,0,0);
    }
};