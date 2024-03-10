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
      
        int dp[201][201];
        memset(dp,0,sizeof(dp));
        dp[0][0] = triangle[0][0];
        for(int i=1;i<row;i++){
            for(int j=0;j<=i;j++){
                int way1 = INT_MAX,way2=INT_MAX;
                if(j<=i-1)way1=dp[i-1][j];
                if(j-1>=0)way2 = dp[i-1][j-1];
                dp[i][j] = min(way1, way2) + triangle[i][j];
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<triangle.size();j++){
            ans= min(ans, dp[triangle.size()-1][j]);
        }
       return ans; 
    }
};