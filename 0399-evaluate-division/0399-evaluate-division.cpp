class Solution {
    double dfs(string node, string dst, unordered_map<string, unordered_map<string, double>>&adj, unordered_map<string, bool>&vis){
        vis[node] = true;
        if(node == dst) return 1.0;
        for(auto nb: adj[node]){
               string newNode = nb.first;
               double cost = nb.second;
               if(!vis[newNode]){
                   double pathCost = dfs(newNode, dst, adj, vis);
                   if(pathCost != -1) return cost * pathCost;
               }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //adj: vector<vector<int>>adj;
        unordered_map<string, unordered_map<string, double>>adj;
        int n = equations.size();
        
        for(int i=0;i<n; i++){
             string u = equations[i][0], v = equations[i][1];
             double w = values[i];
             adj[u][v] = w;
             adj[v][u] = 1.0/w;
        }

        int q = queries.size();
        vector<double>results;
        for(int i=0;i<q;i++){
             auto u = queries[i][0], v = queries[i][1];
             if(adj.find(u)==adj.end() || adj.find(v)==adj.end()){
                results.push_back(-1);
                continue;
             }
             unordered_map<string, bool>vis;
             results.push_back(dfs(u, v, adj, vis));
        }
        return results;
    }
};