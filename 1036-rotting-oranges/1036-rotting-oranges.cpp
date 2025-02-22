class Solution {
    private:
    pair<int,int> nbs[4] = {{-1,0},{1,0},{0,-1},{0, 1}};

public:
   
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<vector<int>>q;
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        
       int time = 0 ;
       while(!q.empty()){
            int sz = q.size();
            while(sz--){
                vector<int> v = q.front();
                int i = v[0], j= v[1];
                q.pop();
                vis[i][j] = true;

                for(int k=0;k<4;k++){
                    int nx = nbs[k].first + i;
                    int ny = nbs[k].second + j;
                  
                    if(isValid(nx, ny, m, n) && !vis[nx][ny] && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                     }
                }
            }

            if(q.size())time++;
       }

       bool isSomeFresh = false;
       for(int i=0;i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                isSomeFresh = true;
            }
        }
       }

    //    for(int i=0;i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout<< grid[i][j]<<" ";
    //     }cout<<endl;
    //    }

       return isSomeFresh? -1: time;

    }

     int isValid(int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
};