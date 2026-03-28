class Solution {
     vector<pair<int,int>>nbs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        //cost is what all keys opened so far. 
        int m = grid.size(), n= grid[0].size();
        queue<tuple<int,int,int>>q;
        bool vis[30][30][70];
        memset(vis, 0, sizeof(vis));
        int keys =0;    
        for(int i=0;i<m;i++){
            for(int j=0;j<n; j++){
                if(grid[i][j] == '@'){
                    q.push({i,j, 0});
                    vis[i][j][0] = true;
                }else if(
                    grid[i][j]>='a' && grid[i][j]<='z'
                ){
                    keys++;
                }
            }
        }
    
        int target = (1<<keys) - 1;
       
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i, j, state] = q.front();
                q.pop();
                if(state == target) return steps;
                for(auto&nb : nbs){
                    int nx = i + nb.first;
                    int ny = j + nb.second;
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny][state]) {
                           if(grid[nx][ny] =='#')continue;
                           else if(grid[nx][ny]>='a'&&grid[nx][ny]<='z'){
                                vis[nx][ny][state] = true; 
                                int keyId = grid[nx][ny] - 'a' ;
                                int new_state = state | (1<<keyId) ;      
                                q.push({nx, ny, new_state});
                           }else if(grid[nx][ny]>='A'&&grid[nx][ny]<='Z'){
                              int keyId = grid[nx][ny] - 'A' ;
                              if( (state & (1<<keyId)) == 0 ) continue;
                              vis[nx][ny][state] = true; 
                              q.push({nx, ny, state});
                           }else if(grid[nx][ny] == '.' || grid[nx][ny] == '@'){
                              vis[nx][ny][state] = true; 
                              q.push({nx, ny, state});
                           }
                           
                    }
                }
                
            }
            steps++;
        }
     return -1;
    }
};