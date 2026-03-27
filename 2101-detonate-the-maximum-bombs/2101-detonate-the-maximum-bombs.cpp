class Solution {
public:
    bool isInside(int x1, int y1, int x2, int y2, int r){
       long long aa = 1LL * (x2-x1) * (x2-x1);
       long long bb = 1LL * (y2-y1) * (y2-y1);
       return (aa + bb) <= (1LL*r*r) ; 
    }

    int bfs(int i, vector<vector<int>>& bombs){
        int m = bombs.size();
        queue<int>q;
        vector<bool>vis(m, false);
        q.push(i);
        vis[i] = true;

        while(!q.empty()){
             int sz = q.size();
             while(sz--){
                int index = q.front(); q.pop();
                int x = bombs[index][0], y = bombs[index][1], r = bombs[index][2];

                for(int j=0;j<m;j++){
                     if(j==index) continue;
                     int nx = bombs[j][0], ny = bombs[j][1], nr = bombs[j][2];
                     if(!vis[j] && isInside(x,y,nx, ny,r)){
                        vis[j] = true;
                        q.push(j);
                     }
                }
             }
             
        }

        int cur = 0;
        for(auto x: vis) if(x) cur++;
        return cur;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
         int m = bombs.size();

         int ans = 0;
         for(int i=0;i<m;i++){
            int cur =bfs(i, bombs);
            ans = max(ans, cur) ;
        }
        return ans;
    }
};