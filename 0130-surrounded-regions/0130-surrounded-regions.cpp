class Solution {
private: 
 pair<int,int>nbs[4] = {{-1,0}, {1,0},{0,-1}, {0,1}};    

public:
    bool isValid(int i, int j, int m, int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    void dfs(int i, int  j, vector<vector<bool>>&vis, vector<vector<char>>& board){
        vis[i][j] = true;
        board[i][j] = 'T';
        
        //nbs:
        for(auto nb:nbs){
            int nx = i + nb.first;
            int ny = j + nb.second;
            if(isValid(nx, ny, board.size(),board[0].size()) && !vis[nx][ny] && board[nx][ny] == 'O'){
                dfs(nx, ny, vis, board);
            }
        }

    } 
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>>vis(m, vector<bool>(n, false));
        //mark all safe Os (boundary Os and those O's which are connected to the bounday Os) with 'T'
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if((i==m-1 || j== n-1 || i==0 || j==0) && board[i][j] == 'O' &&!vis[i][j] ){
                    dfs(i, j, vis, board) ;
                }
            }
        }

        
        //replace all O remaining with X
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }


        //mark all 'T' back to 'O'.
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }   


    }
};