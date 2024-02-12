class Solution {
public:
    long long f(int i, int j, int m, int n, vector<vector<int>>& grid, int dp[201][201]){
        if(i<0 || j<0 || i>=m || j>=n)return INT_MAX;
        if(dp[i][j]!= -1) return dp[i][j];
        long long f1 = grid[i][j] + f(i-1, j,m, n, grid, dp);
        long long f2 = grid[i][j] + f(i, j-1, m,n, grid, dp);
        return  dp[i][j] = min(f1, f2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[201][201];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = grid[0][0];
        // for(int j=1;j<n;j++)dp[0][j]= dp[0][j-1] + grid[0][j];
        // for(int i=1;i<m;i++)dp[i][n-1]= dp[0][j-1] + grid[0][j];
        return (int)f(m-1,n-1, m, n, grid, dp);
    }
};