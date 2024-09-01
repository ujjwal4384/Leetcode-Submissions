class Solution {
public:
  bool isValid(int r, int c, char ch, vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][c]==ch)return false;
        }
        for(int j=0;j<9;j++){
            if(board[r][j]==ch)return false;
        }
        
        int i1,j1,i2,j2;
        i1 = (r/3)*3;
        j1 = (c/3)*3;
        i2 = i1+2;
        j2 = j1+2;
        
        for(int row=i1;row<=i2;row++){
            for(int col=j1;col<=j2;col++){
                if(board[row][col]==ch)return false;
            }
        }
        return true;
    }
    bool f(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(i, j, k, board)){
                            board[i][j] = k;
                            if(f(board))return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
        
    }
};