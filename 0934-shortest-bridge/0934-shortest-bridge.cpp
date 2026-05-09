class Solution {
    pair<int,int>nbs[4] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>&vis, queue<pair<int,int>>&q) {
         vis[i][j] = true;
         q.push({i,j});
         for(auto nb:nbs){
            int nx = nb.first + i;
            int ny = nb.second + j;
            if(nx>=0 && nx< grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==1 && !vis[nx][ny]){
                dfs(nx, ny, grid, vis, q);
            }
         }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        //multisource bfs: start from all ones of one component. mark them as visited. do bfs. moment you reach any other one and that is univsited=> it is shortest distance. 
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            bool found=false;
          for(int j=0;j<n;j++){
               if(grid[i][j] == 1){
                dfs(i, j, grid, vis, q);
                found = true;
                break;
               }
               
          }
          if(found){
                    break;
          }
        }

       
        
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                 auto top = q.front();
                 q.pop();
                 int i = top.first;
                 int j = top.second;
                 
                 for(auto&nb:nbs){
                        int nx = nb.first + i;
                        int ny = nb.second + j;
                        if(nx>=0 && nx< grid.size() && ny>=0 && ny<grid[0].size() && !vis[nx][ny]){
                            if(grid[nx][ny] == 1) return steps;
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                 }
            }
            if(q.size())steps++;
        }
        return steps;
    }
};