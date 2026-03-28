class Solution {

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1){
             return grid[0][0] == 0 ? 1 : -1;
        }
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<tuple<int, int>>q;
        vector<vector<bool>>vis(n, vector<bool>(n, false));
       
        q.push({0,0});
        vis[0][0] = true;
        int steps = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--) {
                auto [i, j] = q.front();
                q.pop();
                for(int l=-1;l<=1;l++){
                    for(int m=-1;m<=1;m++){
                        if(l==0 && m==0) continue;
                        int nx = i + l;
                        int ny = j + m;
                        if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny] == 0){
                            if(nx == n-1 && ny == n-1) return steps + 1 ;
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
           if(q.size()) steps ++;
        }    
        return -1;
    }
};