class Solution {
public:
    int f(int n, vector<int>&dp){
          if(n<=1) return 1;
          if(dp[n]!=-1) return dp[n];
          int count =0;
          for(int root=1;root<=n ; root++){
            count += f(root-1, dp)*f(n-root, dp);
          }

          return dp[n] = count;  
    }

    int numTrees(int n) {
        vector<int>dp(n+1, -1);
      return f(n, dp);   
    }
};