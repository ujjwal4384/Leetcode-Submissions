class Solution {
private:
    int f(int i, int j, vector<vector<int>>& grid, int dp[201][201]){
        if(i<0 || j<0) return 1e8;
        if(i==0 && j==0) return grid[i][j];
        else if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(f(i-1, j, grid, dp), f(i, j-1, grid, dp));
    }    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        int dp[201][201];
        memset(dp, -1, sizeof(dp));
        return f(m-1, n-1, grid, dp);
    }
};