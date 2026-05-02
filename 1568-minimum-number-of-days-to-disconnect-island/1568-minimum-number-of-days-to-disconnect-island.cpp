class Solution {
   pair<int,int>nbs[4]={{-1,0},{1,0},{0,1},{0,-1}}; 
   void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>&vis){
        vis[i][j] = true;
        for(auto& nb:nbs){
            int nx = i + nb.first, ny = j+nb.second;
            if(nx>=0 && ny>=0 && nx<grid.size() && ny < grid[0].size() && grid[nx][ny]==1 &&!vis[nx][ny] ){
                   dfs(nx, ny, grid, vis);
            }
        }       
   }

   int countIslands(vector<vector<int>>& grid){
       int m = grid.size(), n = grid[0].size();
       vector<vector<bool>>vis(m, vector<bool>(n, false));
       int count = 0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
             if(grid[i][j] ==1 && !vis[i][j]){
                  count++;
                  dfs(i, j, grid, vis);
             }
        }
       }
        return count;
   }
public:

    int minDays(vector<vector<int>>& grid) {
        //ans can be  one of [0,1,2].
        int m = grid.size(), n = grid[0].size();
        int initalIslandCount = countIslands(grid);
        cout<<initalIslandCount<<endl;
        if(initalIslandCount != 1) return 0;

        //check for one. break a node such that it breaks into two components. articulation point. //do brute force 
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(countIslands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
         }

         return 2; // else corner element will always be there having two adjacne land cells.
    }
};