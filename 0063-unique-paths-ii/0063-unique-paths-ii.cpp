class Solution {
    int f(int i, int j, int dp[101][101], vector<vector<int>>& obstacleGrid){
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j] == 1)return 0;
        if(i==0 && j==0) return 1;
        else if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = f(i-1, j, dp, obstacleGrid) + f(i, j-1, dp, obstacleGrid);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        return f(obstacleGrid.size()-1 , obstacleGrid[0].size()-1, dp, obstacleGrid);
    }
};