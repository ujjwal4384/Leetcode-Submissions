class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
       int m = grid.size(), n= grid[0].size();
       vector<vector<int>>pre(m,vector<int>(n,0));
       int ans =0;
       for(int i=0;i<m; i++){
            for(int j=0;j<n; j++){
  pre[i][j] = grid[i][j]+ (i-1>=0 ? pre[i-1][j]: 0)+(j-1>=0?pre[i][j-1]:0)-(i-1>=0 && j-1>=0 ?pre[i-1][j-1]:0);
             ans += (pre[i][j]<=k);
            }
       }
       return ans;
    }
};