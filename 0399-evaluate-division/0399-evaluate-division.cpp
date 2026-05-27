class Solution {
private:
double dfs(string node, string dst, unordered_map<string, unordered_map<string,double>>&adj, unordered_map<string,bool>&vis){
    if(node == dst)return 1.0;
    vis[node] = true;
    for(auto& p: adj[node]){   
              string v = p.first;
              double cost = p.second;
              if(!vis[v]){
                    double pathCost = dfs(v, dst, adj, vis);
                    if(pathCost != -1){
                        return pathCost * cost;
                    }   
              } 
    }
   return -1; 
}    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string,double>>adj;
        for(int i=0;i<equations.size(); i++){
            string u = equations[i][0], v = equations[i][1];
            double val = values[i];
            adj[u][v] = val;
            adj[v][u] = 1.0/val;
        }
        vector<double>ans;
        for(auto& q: queries){
            string u = q[0], v= q[1];
            if(adj.find(u) == adj.end() || adj.find(v)== adj.end()){
                ans.push_back(-1);
                continue;
            }
            unordered_map<string,bool>vis;
            double cost = dfs(u, v, adj, vis);
            ans.push_back(cost);
        }
       return ans; 
    }
};