class Solution {
public:
    int f(int i, int j, vector<vector<int>>& obstacleGrid, int dp[101][101]){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]= f(i-1, j, obstacleGrid, dp)+ f(i, j-1, obstacleGrid, dp);
    }
    int uniquePathsWithObstaclesMemo(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        if(m==1 && n==1) return 1;
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        return f(m-1, n-1, obstacleGrid, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        if(m==1 && n==1) return 1;
        int dp[101][101];
        memset(dp, 0, sizeof(dp));
        dp[1][1] =1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                 if(i==1 && j==1)continue;
                 if(obstacleGrid[i-1][j-1]){
                     dp[i][j] = 0;
                     continue;
                 }
                 dp[i][j]= dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};