class Solution {
    int timer = 0;
    void dfs(int node, int par, vector<vector<int>>&adj, vector<bool>&vis, vector<int>&tin, vector<int>&low, vector<vector<int>>&bridges){
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;

        for(auto&nb:adj[node]){
               if(nb == par) continue;
               if(!vis[nb]){
                    dfs(nb, node, adj, vis, tin, low, bridges);
                    low[node] = min(low[node], low[nb]);
                    //check if this edge is a bridge 
                    if(low[nb] > tin[node]) {
                        bridges.push_back({node, nb});
                    }
               }else{
                    low[node] = min(low[node], low[nb]);
               }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>bridges;
        vector<vector<int>>adj(n);
        for(auto v: connections){
            int x = v[0], y= v[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool>vis(n, false);
        vector<int>tin(n, 0);
        vector<int>low(n, n+1);//lowest ancestor i can go back to without using the bridge i came from.(par)
        dfs(0, -1, adj, vis, tin, low, bridges);
        return bridges;
    }
};