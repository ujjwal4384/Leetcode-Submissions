class Solution {
    pair<int,int>nbs[4] = {{-1,0}, {1,0}, {0, 1}, {0, -1}};
    int f(int i, int j, vector<vector<int>>& grid, int& count_empty, int cur){
       
        if(grid[i][j] == 2) return cur == count_empty;

        int original_val = grid[i][j];
        if(original_val==0)cur++;
        grid[i][j] = -1;
        int ways = 0;
        for(auto& nb: nbs){
              int nx = i + nb.first;
              int ny = j + nb.second;
              if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size() || grid[nx][ny]== -1)continue;
              ways += f(nx, ny, grid, count_empty, cur);
              
        }

        grid[i][j] = original_val;
       
        return ways;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int st_x=-1,st_y=-1,en_x=-1,en_y=-1;
        int count_empty = 0;
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                   if(grid[i][j] == 1){
                    st_x = i, st_y = j;

                   }else if(grid[i][j] == 2){
                    en_x = i, en_y = j;
                   } else if(grid[i][j] == 0){
                    count_empty++;
                   }
            }
        }
        int cur = 0;
        return f(st_x, st_y, grid,count_empty, cur);
    }
};