class Solution {
public:
    int adj[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    
    bool isValid(int i, int j, int m, int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //0= empty cell, 1 = fresh, 2-> rotten orange
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int cnt_fresh=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                    vis[i][j]= true;
                }
                else if(grid[i][j]==1)cnt_fresh++;
            }
        }
      
        
      // cout<<"HI\n";
        int time=0;
        while(!q.empty()){
            int sz = q.size();
            bool add=0;
            while(sz--){
                auto p = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = p.first+ adj[i][0];
                    int ny = p.second + adj[i][1];
                    if(isValid(nx,ny,m,n) && !vis[nx][ny] && grid[nx][ny]==1){
                        add=1;
                        // cout<<nx<<","<<ny<<endl;
                        cnt_fresh--;
                        vis[nx][ny]=true;
                        q.push({nx, ny});
                    }
                }
            }
            if(add)time++;
        }
       return cnt_fresh>0 ? -1: time; 
    }
};