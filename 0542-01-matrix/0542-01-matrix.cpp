class Solution {
private:
 pair<int,int>nbs[4]= {{-1,0},{1,0},{0,-1},{0,1}};
public:
    bool isValid(int i,int j,int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        
        int m = v.size();
        int n = v[0].size();
        queue<vector<int>>q;
        vector<vector<int>>dis(m, vector<int>(n, INT_MAX));
        for(int i=0; i<m;i++){
            for(int j=0; j<n ; j++){
                if(v[i][j] == 0){
                    dis[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

       
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                 vector<int>data = q.front();
                 q.pop();
                 int x = data[0];
                 int y = data[1];
                    
                 for(auto nb:nbs){
                    int nx = nb.first + x;
                    int ny = nb.second + y;
                    if(isValid(nx, ny, m, n) && dis[nx][ny] == INT_MAX){
                        dis[nx][ny] = dis[x][y] + 1;
                        q.push({nx, ny});
                    }
                 } 
            }
          
        }

       return dis; 
    }
};