class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n= grid[0].size();
       
       int ans =0;
       vector<vector<int>>preX(m, vector<int>(n,0)), preY(m, vector<int>(n,0));
       
       for(int i=0;i<m; i++){
            for(int j=0;j<n; j++){
                preX[i][j] = grid[i][j] =='X';
                preY[i][j] = grid[i][j] =='Y';
  preX[i][j] += (i-1>=0 ? preX[i-1][j]: 0)+(j-1>=0?preX[i][j-1]:0)-(i-1>=0 && j-1>=0 ?preX[i-1][j-1]:0);
  preY[i][j] += (i-1>=0 ? preY[i-1][j]: 0)+(j-1>=0?preY[i][j-1]:0)-(i-1>=0 && j-1>=0 ?preY[i-1][j-1]:0);
           ans +=  (preX[i][j] > 0) && (preX[i][j] == preY[i][j]);
            }
       }
       return ans;
    }
};