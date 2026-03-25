class Solution {
    pair<int,int>nbs[4] = {{-1,0},{1,0},{0,1},{0,-1}};   
public:
    void dfs(int i, int j, vector<vector<char>>& board){
        if(board[i][j] == '.') return;
        board[i][j] = '.'  ;
        for(auto nb: nbs){
                int nx = i + nb.first;
                int ny = j + nb.second;
                if(nx>=0 && nx < board.size() && ny >=0 && ny < board[0].size() && board[nx][ny] == 'X'){         
                    dfs(nx, ny, board);
                }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
          int ans  =0;
          for(int i=0;i<board.size();i++){
             for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 'X'){
                      dfs(i, j, board);
                      ans++;
                }
             }
          }
       return ans;   
    }
};