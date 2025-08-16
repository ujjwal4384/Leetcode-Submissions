class Solution {
public:
    bool isCycleExist(int node, vector<vector<int>>&adj, vector<bool>&vis,vector<bool>&recVis){
        vis[node] = true;
        recVis[node] = true;
        for(auto x: adj[node]){
            if(recVis[x]) return true;
            if(!vis[x] && isCycleExist(x, adj, vis, recVis)){
                return true;        
            }
        }
        
        recVis[node] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& v) {
         vector<vector<int>>adj(n); 
         for(auto x:v){
            adj[x[1]].push_back(x[0]);
         }
         vector<bool>vis(n, false), recVis(n, false);   
         for(int i=0 ;i<n; i++){
            if(!vis[i] && isCycleExist(i, adj, vis, recVis)){
                return false;
            } 
         }
         return true;
    }
};