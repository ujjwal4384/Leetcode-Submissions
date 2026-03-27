class Solution {
public:
    bool checkTopRemoval(vector<vector<int>>& grid, long long& sum){
        int m = grid.size(), n = grid[0].size();
        long long topSum = 0;
        unordered_set<long long>seen;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                topSum += grid[i][j];
                seen.insert(grid[i][j]);
            }
            long long delta = topSum - (sum - topSum) ;
            if(delta == 0) return true;
            if(delta > 0){
                 if(i==0 || n==1){
                     if((grid[0][0] == delta || grid[0][n-1] == delta || grid[i][0] == delta || grid[i][n-1] == delta)) return true;
                 }else{
                    if(seen.find(delta) != seen.end()) return true;
                 }
            }
        }
        return false;
    }

    vector<vector<int>> rotate(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - 1 - i] = grid[i][j];
            }
        }
        return res;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        for(auto x:grid) for(auto y:x) sum += y;
         for(int i=0;i<4;i++){
             grid = rotate(grid);
             if(checkTopRemoval(grid, sum)) return true;
         }
         return false;
    }
};