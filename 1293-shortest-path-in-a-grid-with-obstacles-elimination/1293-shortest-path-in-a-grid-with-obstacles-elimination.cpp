class Solution {
     vector<pair<int,int>>nbs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if(m==1 && n==1){
            return k>=1 ? 0 : -1;
        } 

        bool vis[50][50][1600];
        memset(vis, 0, sizeof(vis));
        queue<tuple<int,int,int>>q;
        if(grid[0][0] == 1){
            vis[0][0][1] = true;
            q.push({0,0,1});
        }
        else {
            vis[0][0][0] = true;
            q.push({0,0,0});
        }
       
        
        int steps = 0;
        while(!q.empty()){
              int sz = q.size();
              while(sz--){
                   auto [i,j,cost] = q.front();
                   q.pop();
                    for(auto&nb:nbs){
                        int nx = i + nb.first;
                        int ny = j + nb.second;
                        if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny][cost]){
                            int new_cost = cost + (grid[nx][ny] == 1);
                            if(new_cost > k) continue;
                              vis[nx][ny][cost] = 1 ;
                            if(nx == m-1 && ny == n-1) return steps+1;
                            q.push({nx, ny, new_cost});
                        }
                    }
              }
             
          if(q.size())steps++;
        }
        return -1;
    }

};