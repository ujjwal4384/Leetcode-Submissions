class Solution {
    int f(int i, int j, int dp[101][101]){
        if(i==0 && j==0) return 1;
        else if(i<0 || j<0) return 0;
        else if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i-1, j, dp) + f(i, j-1, dp);
    }
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        return f(m-1,n-1, dp);
    }
};