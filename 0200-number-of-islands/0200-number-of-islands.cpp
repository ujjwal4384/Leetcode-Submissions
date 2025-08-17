class Solution {
private :
     pair<int,int>adj[4] = {{-1,0},{0,-1},{1,0},{0,1}};
     bool isValid(int i, int j, int m, int n){
        return i>=0 && j>=0 && i<m && j<n;
     }
public:
    void dfs(int i, int j, int m, int n,vector<vector<char>>& grid, vector<vector<bool>>&vis ){
        vis[i][j] = true;
        for(auto p: adj){
            int nx = i + p.first;
            int ny = j + p.second;

            if(isValid(nx, ny, m, n) && grid[nx][ny]=='1' && !vis[nx][ny]){
                vis[nx][ny] = true;
                dfs(nx, ny, m, n, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        int count =0;    
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count ++;
                    dfs(i, j, m, n, grid, vis);
                }
            }
        }

        return count;
    }
};