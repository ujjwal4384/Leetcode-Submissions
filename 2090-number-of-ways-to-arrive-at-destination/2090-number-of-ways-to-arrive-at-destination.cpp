class Solution {
    int  MOD = 1e9+7;
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto v:roads){
            int from=v[0],to=v[1],time=v[2];
            adj[from].push_back({to, time});
            adj[to].push_back({from, time});
        }

        vector<long long >dist(n, LLONG_MAX);   
        vector<long long>ways(n, 0);    
        set<pair<long long,int>>s;
        s.insert({0LL, 0});
        dist[0]=0;
        ways[0] = 1;

        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            long long d = it->first;
            s.erase(it);
            if (d > dist[node]) continue;
            for(auto nb: adj[node]){
                int adjNode = nb.first;
                int time = nb.second;
                if(dist[adjNode] > d + time){
                    if(dist[adjNode] != LLONG_MAX){
                        s.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = d + time;
                    s.insert({dist[adjNode], adjNode});

                    ways[adjNode] = ways[node];
                }else if(dist[adjNode] == d + time){
                    ways[adjNode] = (ways[adjNode] + ways[node])%MOD; 
                }    
            }
        }

       
       return ways[n-1];
    }
};