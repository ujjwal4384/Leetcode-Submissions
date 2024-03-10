class Solution {
public:
    int f(int row,int col, vector<vector<int>>& triangle, int dp[201][201]){
        if(row==0 && col==0)return triangle[0][0];
        if(col>row ||col<0)return INT_MAX;
        if(dp[row][col]!=-1)return dp[row][col];
        int result=INT_MAX;
        int way1 = f(row-1, col, triangle, dp);
        int way2= f(row-1,col-1, triangle, dp);
        result=min(way1,way2)+triangle[row][col];
        return dp[row][col] = result;
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        int ans=INT_MAX;
        int dp[201][201];
        memset(dp,-1,sizeof(dp));
        for(int col=0;col<row;col++){
           ans= min(ans, f(row-1, col, triangle,dp));
        }
       return ans; 
    }
};