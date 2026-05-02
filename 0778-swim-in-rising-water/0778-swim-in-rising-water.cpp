class Solution {
    pair<int,int>nbs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isPossible(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& mid){
        vis[i][j] = true;
        if(i==grid.size()-1 && j==grid[0].size() - 1){
            return true;
        }

        for(auto nb: nbs){
            int nx = i + nb.first;
            int ny = j + nb.second;
            if(nx>=0 && ny>=0 && nx<grid.size() && ny < grid[0].size() && !vis[nx][ny]){
                if(grid[nx][ny] > mid) continue;
                if(isPossible(nx, ny, grid, vis, mid)) return true;
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        if(n==1 && n==1) return grid[0][0];
        int l =0, r= n*n -1 ;
        int ans = r;
        while(l<=r){
             int mid = (l+r)>>1 ;
             vector<vector<bool>> vis(n, vector<bool>(n, false));
             if(grid[0][0] <=mid && isPossible(0, 0, grid, vis, mid)){
                    ans = mid;
                    r = mid -1 ;
             }else{
                 l = mid + 1;
             }
        }
        return ans;
    }
};