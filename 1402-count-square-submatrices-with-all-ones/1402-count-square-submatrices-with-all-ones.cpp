class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        
        int count =0; 
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int i=0;i<m ;i++){
          for(int j=0; j<n ; j++){
             if(matrix[i][j] == 1){
                   int a = i-1>=0 ? dp[i-1][j] : 0;
                   int b = j-1>=0 ? dp[i][j-1] : 0;
                   int c = i-1>=0 && j-1>=0 ? dp[i-1][j-1] : 0;
                   dp[i][j] = min(a, min(b, c)) + 1;
                   count += dp[i][j]; 

             }
          } 
        }
        

     return count;
    }
};