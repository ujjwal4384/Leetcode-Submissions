class Solution {
    
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n= graph.size();
        vector<vector<bool>>vis(n, vector<bool>(1<<n, false));
        //multi source bfs. connected graph. shortest path. all path equal weights
        queue<tuple<int,int, int>>q;
        for(int node=0;node<n;node++){
            int mask = (1<<node) ;
            int step = 0;
            q.push({node,mask, step});
            vis[node][mask] = true;
        }
        int target_mask = (1<<n) -1 ; //all nodes visited 1111111
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto [node, mask, steps] = q.front(); 
                q.pop();
                for(auto nb: graph[node]){
                      if(nb == node)continue;
                      int new_mask = mask | (1<<nb) ;
                      if(new_mask == target_mask) return steps+1;
                      if(!vis[nb][new_mask]){
                        q.push({nb, new_mask, steps+1});
                        vis[nb][new_mask] = true;
                      }
                }
            }
        }
        return 0;
    }
};