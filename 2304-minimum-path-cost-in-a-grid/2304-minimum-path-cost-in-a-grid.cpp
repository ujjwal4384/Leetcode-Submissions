class Solution {
    vector<vector<int>>dp;
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost){
       if(i==grid.size()-1) return grid[i][j];
       if(dp[i][j]!=-1) return dp[i][j];
       int ans = INT_MAX;
       int src = grid[i][j];
       for(int j=0;j<grid[0].size(); j++){
            int moveFee = moveCost[src][j];
            int cost = src + moveFee;
            int totCost = cost + solve(i+1,j, grid, moveCost);
            ans = min(ans, totCost);
       } 
  
       return dp[i][j] = ans;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        dp.assign(grid.size(), vector<int>(grid[0].size(),-1));
        int ans = INT_MAX;
        for(int j=0;j<grid[0].size(); j++) {
            int curCost = solve(0,j, grid, moveCost);
            ans = min(ans, curCost);
        }
        return ans;
    }
};
