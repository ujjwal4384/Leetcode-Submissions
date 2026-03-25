class Solution {
 pair<int,int>nbs[4] = {{-1,0},{1,0},{0,1},{0,-1}};   
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int m = grid.size(), n= grid[0].size();
       queue<tuple<int,int>>q;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 2) q.push({i,j});
        }
       }
       int time = 0;
       while(!q.empty())  {
            int sz = q.size();
          
            while(sz--){
                auto [i, j] = q.front();
                q.pop();
                for(auto nb:nbs){
                    int nx = i + nb.first;
                    int ny = j + nb.second;
                    if(nx>=0 && ny>=0 && nx<m && ny <n && grid[nx][ny]==1){
                         q.push({nx, ny});
                         grid[nx][ny] = 2;
                    }
                }
            }
           if(q.size()>0)time++;
       }
       
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1) return -1;
        }
       }
       return time;
    }
};