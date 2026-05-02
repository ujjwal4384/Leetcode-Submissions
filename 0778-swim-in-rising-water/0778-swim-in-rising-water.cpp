class Solution {
    pair<int,int>nbs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        vector<vector<bool>>vis(n, vector<bool>(n, false));
        vis[0][0] = true;
        pq.push({grid[0][0], {0,0}}); 
        while(!pq.empty()){
            auto [miniMaxCostSoFar, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();
            if(x==n-1 && y==n-1) return miniMaxCostSoFar;
            for(auto& nb: nbs){
                int nx = x + nb.first;
                int ny = y + nb.second;
             if(nx>=0 && ny>=0 && nx<grid.size() && ny < grid[0].size() && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    pq.push({ max(miniMaxCostSoFar, grid[nx][ny]), {nx, ny}});
             }
            }
        }
        return 0;
    }
    
};