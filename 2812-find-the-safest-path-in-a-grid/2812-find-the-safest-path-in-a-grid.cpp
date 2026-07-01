class Solution {
    pair<int,int> nbs[4] = {{-1,0},{1,0},{0,1},{0,-1}};
    
    // Helper function to check if a valid path exists with safeness >= max_required
    bool isValid(int max_required, vector<vector<int>>& dis) {
        int m = dis.size(), n = dis[0].size();
        
        // If the start or end cell itself doesn't satisfy the minimum safeness requirement
        if (dis[0][0] < max_required || dis[m-1][n-1] < max_required) return false;
        
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        q.push({0, 0});
        vis[0][0] = true;
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            if (i == m - 1 && j == n - 1) return true; // Destination reached successfully
            
            for (auto nb : nbs) {
                int nx = i + nb.first;
                int ny = j + nb.second;
                
                // Only move to valid, unvisited neighbors that meet our safeness requirement
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] && dis[nx][ny] >= max_required) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
         
         // Direct exit if start or end contains a thief
         if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;
         
         vector<vector<int>> dis(m, vector<int>(n, -1));
         queue<pair<int,int>> q;
         
         // Step 1: Multi-source BFS to populate distances to closest thief
         for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                 if(grid[i][j] == 1){
                    dis[i][j] = 0;
                    q.push({i, j});
                 }
            }
         }
         
         while(!q.empty()){
               auto [i, j] = q.front();
               q.pop();
               
               for(auto nb : nbs){
                    int nx = i + nb.first;
                    int ny = j + nb.second;
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && dis[nx][ny] == -1){
                        dis[nx][ny] = dis[i][j] + 1; // Pull directly from parent cell
                        q.push({nx, ny});
                    }
               }
         }

         // Step 2: Binary Search on the maximum safeness factor
         int l = 0, r = min(dis[0][0], dis[m-1][n-1]), ans = 0;
         while(l <= r){
               int mid = l + (r - l) / 2;
               if(isValid(mid, dis)){
                  ans = mid;         // Mid is viable, try to maximize further
                  l = mid + 1;
               } else {
                  r = mid - 1;       // Mid is too restrictive, drop requirement
               }          
         }
         return ans;  
    }
};