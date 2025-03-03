class Solution {
public:
    bool dfsSolve(int node, vector<vector<int>>& graph,vector<bool>&vis,vector<bool>&pathVis, vector<bool>&check){
        vis[node] = true;
        pathVis[node] = true;
        check[node] = false;

        for(auto x: graph[node]){
            if(vis[x]){
                if(pathVis[x]){
                    //cycle detected
                    return true;
                }else{
                   
                    continue;
                }
            }else{
                bool isCycle = dfsSolve(x,graph, vis, pathVis, check);
                if(isCycle){
                    return true;
                }
            }
        }

        pathVis[node] = false;
        check[node] = true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>vis(n,false);
        vector<bool>pathVis(n,false);
        vector<bool>check(n,false);
        for(int i=0; i<n ; i++){
            if(!vis[i]){
                dfsSolve(i, graph,vis, pathVis, check);
            }
             
        }

      vector<int>safeNodes;
      for(int i=0; i<n ;i++){
        if(check[i])safeNodes.push_back(i);
      }  
      return safeNodes;  
    }
};