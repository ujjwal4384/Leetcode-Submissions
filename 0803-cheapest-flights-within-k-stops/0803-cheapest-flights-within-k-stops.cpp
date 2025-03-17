class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int maxSteps = min(n+1, k+1);
        vector<vector<pair<int,int>>>adj(n);
        
        for(auto v:flights){
            adj[v[0]].push_back({v[1], v[2]});
        }

        queue<int>q;
        int dis[105][105];
        for(int i=0;i<105;i++){
          for(int k=0; k<105; k++){
            if(i==src)dis[i][k] = 0;
            else dis[i][k] = INT_MAX;
          }
        }
        q.push(src);
        int res = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                  int node = q.front();
                  q.pop() ;
                  if(node==dst){
                     continue;
                  }
                  else if(res>=maxSteps)continue;
                  for(auto p:adj[node]){
                    int adjNode = p.first;
                    int w = p.second;

                    if(dis[adjNode][res+1] > dis[node][res] + w){
                        dis[adjNode][res+1] = dis[node][res] + w;
                        q.push(adjNode);
                    }
                  }
            }
            res ++;
        }
        int ans = INT_MAX;
        for(int i=0;i<=maxSteps;i++){
            ans = min(ans, dis[dst][i]);
        }
        return ans == INT_MAX ? -1 : ans;

    }
};