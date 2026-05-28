class Solution {
public:
    bool isit(vector<vector<char>>&board,string word,int idx,int i,int j){
        if(idx==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[idx]) return false;
        char temp=board[i][j];
        board[i][j]='#';
        bool found=(isit(board,word,idx+1,i+1,j) || isit(board,word,idx+1,i-1,j) || isit(board,word,idx+1,i,j+1) || isit(board,word,idx+1,i,j-1));
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isit(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};