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
        unordered_map<string, unordered_map<string, double>>dis;
        int n = equations.size();
        set<string>nodes;
        for(int i=0;i<n; i++){
             string u = equations[i][0], v = equations[i][1];
             double w = values[i];
             dis[u][v] = w;
             dis[v][u] = 1.0/w;
             dis[u][u] = 1.0;
             dis[v][v] = 1.0;
             nodes.insert(u);
             nodes.insert(v);
        }
        for(auto& via: nodes){
            for(auto& i: nodes){
                for(auto& j:nodes){
                       if(dis[i].find(j) != dis[i].end())continue;
                       if(dis[i].find(via) != dis[i].end() && dis[via].find(j)!= dis[via].end()){
                          dis[i][j] = dis[i][via] * dis[via][j] ;
                       }
                }
            }
        }
        int q = queries.size();
        vector<double>results;
        for(int i=0;i<q;i++){
             auto u = queries[i][0], v = queries[i][1];
             if(dis.find(u) == dis.end() || dis[u].find(v) == dis[u].end()){
                results.push_back(-1);
             }else{
                results.push_back(dis[u][v]);
             }
        }
        return results;
    }
};