class Solution {
public:
    int f(int i, int j, int dp[101][101]){
        if(i==0 && j==0){
            return 1;
        }
        else if(i<0 || j<0){
            return 0;
        }
        else if(dp[i][j] != -1) return dp[i][j];

        int fromTop = 0,fromLeft=0;
        fromTop = f(i-1, j, dp);
        fromLeft = f(i,j-1, dp);

        return dp[i][j] =  fromTop + fromLeft;
    }
    int uniquePaths(int m, int n) {
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        return f(m-1, n-1, dp);
    }
};