class Solution {
public:
    pair<int,int> nbs[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    bool isValid(int x, int y, int m,int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
  
    int f(pair<int,int>node, pair<int,int>&dst, vector<vector<int>>& v, int vis[21][21], int c){
        int x = node.first, y= node.second; 
          
        if(x==dst.first && y==dst.second){
           
            return c==0 ;
        }
       
       
        
        int count = 0;
        for(int i=0;i<4;i++){

            int nx = x + nbs[i].first;
            int ny = y + nbs[i].second;
            
            if(isValid(nx,ny, v.size(), v[0].size()) && !vis[nx][ny] && v[nx][ny]!=-1){
                 vis[x][y] = true;
               pair<int,int>z = {nx,ny};
               count += f(z, dst, v, vis, c-1); 
                vis[x][y] = false;
              
            }
        }

        // vis[x][y] = false;
       return count;    
    }

    int uniquePathsIII(vector<vector<int>>& v) {
       int m=v.size();
       int n=v[0].size();
       pair<int,int>src = {0,0};
       pair<int,int>dst = {m-1,n-1};
       int c = 1;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
               if(v[i][j] == 1){
                 src = {i,j};
                
               }
               else if(v[i][j] ==2){
                 dst = {i,j};
                
               }else if(v[i][j]==0)c++;
        }
       }
       int vis[21][21];
       
       memset(vis, 0, sizeof(vis));
       return f(src, dst, v, vis, c);
    }
};