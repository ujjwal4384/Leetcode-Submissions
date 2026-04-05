class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        
        queue<tuple<int,int,int>>q;//stops, node, cost
        q.push({0, src, 0});
        vector<int>dis(n, 1e9);
        dis[src] = 0;

        vector<vector<pair<int, int>>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1], e[2]});
        }

        while(!q.empty()){
             auto [stops, node, cost] = q.front();
             q.pop();
             if(stops > k ) continue;
             for(auto p:adj[node]){
                    int nb = p.first;
                    int w = p.second;
                    if(cost + w < dis[nb] ){
                         dis[nb] = cost + w;
                         q.push({stops+1, nb, cost + w});
                    }
             }
        }
        return dis[dst] == 1e9 ? -1 : dis[dst];
    } 
};