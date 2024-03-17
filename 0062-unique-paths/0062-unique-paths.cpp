class Solution {
public:
    int uniquePathsCombinatorial(int m, int n) {
        if(m==1 || n==1) return 1;
        //math.comb(m+n-2, m-1)
        //total steps= m-1 + n-1 = m+n-2.//just find ways of moving down,bcz corresponding to each such way there is only one way to go right on remaining steps.
        //(m+n-2)!/(m-1)!(n-1)!  
        
        //(m+n-2)*....(m)/(n-1)!
        if(m<n)swap(m,n);
        long long ans=1;
        for(int i=1; i<=n-1; i++){
            long long num = (m+n-1-i);
            long long den = (i);
            ans=  1LL * ans * num/den;
        }
        return (int)ans;
        
    }
    int f(int i, int j, int dp[][101]){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j] = f(i-1, j, dp) + f(i, j-1, dp);
    }
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        int dp[101][101];
         memset(dp,-1,sizeof(dp));
         int ans = f(m-1, n-1, dp);
        return ans;
        
    }
};