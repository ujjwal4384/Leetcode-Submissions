class Solution {
    vector<pair<int,int>>nbs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<tuple<int, int>>q;
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--) {
                auto [i, j] = q.front();
                q.pop();
                for(auto& nb:nbs){
                    int nx = i + nb.first;
                    int ny = j + nb.second;
                    if(nx>=0 &&nx<n && ny>=0 && ny<n && !vis[nx][ny]){
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }

            }
           if(q.size()) steps ++;
        }

        
        return steps==0 ? -1 : steps;
    }
};