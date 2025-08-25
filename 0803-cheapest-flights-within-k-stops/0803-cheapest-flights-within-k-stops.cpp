class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {    
        vector<vector<pair<int,int>>>adj(n);
        
        for(auto edge:flights){
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].push_back({v,w});
        }
        queue<int>q;
        vector<int>dist(n, INT_MAX);
    
        dist[src] = 0; 
        q.push(src);
        int steps = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node =q.front();
                q.pop();
                if(steps>k && node != dst){
                    continue;
                }
                if(steps> k+1 && node == dst){
                    continue;
                }
                
                for(auto p:adj[node]){
                    int adjNode = p.first;
                    int w = p.second;
                    if(0LL + dist[node] + w  < dist[adjNode]){
                        dist[adjNode] = dist[node] + w;
                        q.push(adjNode);
                    }
                }    
            }
            steps++;
            
        }
       return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};