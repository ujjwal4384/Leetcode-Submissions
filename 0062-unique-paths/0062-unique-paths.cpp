class Solution {
    int f(int i, int j, int dp[101][101]){
        if(i==0 && j==0) return 1;
        else if(i<0 || j<0) return 0;
        else if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i-1, j, dp) + f(i, j-1, dp);
    }
public:
    int uniquePaths(int m, int n) {
        if (m < n) swap(m, n);
        
        if(m==1 || n==1) return 1;
        //total m-1 c+ n-1 steps to reach from top-left to bottom-right
        //out of which m-1 will be in down directioj and n-1 wil be in right direfction
        // = ways = (m+n-2) C (m-1)

        // (m+n-2)!/ (m-1)!(n-1)!   = (m+n-2)(m+n-1)....(m) / (n-1)(n-2)...(1)


        long long ans = 1;
        for(int i=1;i<=n-1;i++){
            ans =   ans * (m+n-i-1) / i ;
        }
        return (int)ans;
    }
};
        