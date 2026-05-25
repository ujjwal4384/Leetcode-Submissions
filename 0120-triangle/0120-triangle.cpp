class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for(int row=1; row<n; row++){
            for(int col = 0; col<=row; col++){
                  int a = col <=row-1 ? dp[row-1][col] : INT_MAX;
                  int b = col-1 >=0 ? dp[row-1][col-1] : INT_MAX;
                  dp[row][col] = triangle[row][col] +  min(a, b);
            }
        }
      return *min_element(dp[n-1].begin(), dp[n-1].end());  
    }
};