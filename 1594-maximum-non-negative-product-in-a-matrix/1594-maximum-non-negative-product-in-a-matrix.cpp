class Solution {
    pair<long long, long long> dp[20][20];
    int MOD = 1e9 + 7;
public:
    pair<long long, long long> solve(int row, int col, vector<vector<int>>& grid){
        if(row==0 && col==0) return {grid[0][0], grid[0][0]};
        if(dp[row][col].first != 1e18 && dp[row][col].second != 1e18 ) return dp[row][col];
        long long max_prod = LLONG_MIN;
        long long min_prod = LLONG_MAX;
        if(row>0){
              auto pa = solve(row-1, col, grid);
              max_prod = max({grid[row][col]*pa.first, grid[row][col]* pa.second}) ;
              min_prod = min({grid[row][col]*pa.first, grid[row][col]* pa.second}) ;
        }
       if(col>0){
              auto pa = solve(row, col-1, grid);
        max_prod = max({max_prod, grid[row][col]*pa.first, grid[row][col]* pa.second}) ;
        min_prod = min({min_prod, grid[row][col]*pa.first, grid[row][col]* pa.second}) ;
       }
        
     return dp[row][col] = {max_prod, min_prod};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        for(int i=0;i<std::size(dp);i++)
           for(int j=0;j<std::size(dp[i]); j++)
              dp[i][j] = {1e18, 1e18};
        
        
        
        auto p = solve(grid.size()-1, grid[0].size()-1, grid);
        
        return p.first<0 ? -1: (p.first)%MOD;
    }
};