class Solution {
public:
    int adj[4][2]={{-1,0},{1,0}, {0,-1}, {0,1}};
    bool isValid(int i,int j, int m, int n){
          if(i<0 ||j<0 || i>=m || j>=n) return false;
        return true;
    }
    
    bool f(int pos, int i, int j, vector<vector<char>>& board, string& word, vector<vector<bool>>&vis, int& m, int& n){
     
    if(pos==word.size()-1) return true;
       vis[i][j]=1; 
    
     for(int p=0;p<4;p++){
            
            int nx= i+adj[p][0],ny=j+adj[p][1];
            if(isValid(nx,ny,m,n) &&  word[pos+1]==board[nx][ny] && !vis[nx][ny] ){
                if(f(pos+1, nx, ny, board, word, vis, m ,n)) return true;
            }
        }
     vis[i][j]=0; 
       
    return false;    
}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n= board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vector<vector<bool>>vis(m,vector<bool>(n,false));
                    if(f(0, i, j, board, word, vis, m, n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};