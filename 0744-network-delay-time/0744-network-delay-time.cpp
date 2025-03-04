class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto v:times){
            int from=v[0],to=v[1],time=v[2];
            adj[from].push_back({to, time});
        }

        vector<int>dist(n+1, INT_MAX);    
        set<pair<int,int>>s;
        s.insert({0, k});
        dist[k]=0;

        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            int d = it->first;
            s.erase(it);
            for(auto nb: adj[node]){
                int adjNode = nb.first;
                int time = nb.second;
                if(0LL + dist[adjNode] > 0LL + d + time){
                    dist[adjNode] = d + time;
                    s.insert({dist[adjNode], adjNode});
                }    
            }
        }

       int ans = -1;
       for(int i=1;i<=n;i++) {
         ans = max(ans, dist[i]);
       }

       return ans == INT_MAX ? -1 : ans;
    }
};