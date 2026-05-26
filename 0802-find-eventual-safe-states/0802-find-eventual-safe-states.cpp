class Solution {
    bool dfs(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&safe){
        vis[node] = 1;
        for(auto& adjNode: adj[node]){
              if(vis[adjNode] == 2)continue;
              else if(vis[adjNode] == 1) return true;
              else if(vis[adjNode] == 0){
                     bool hasCycle = dfs(adjNode, adj, vis, safe);
                     if(hasCycle) return true;
              }
        }
        safe[node] = true;
        vis[node] = 2;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
             for(auto&x: graph[i])
                  adj[i].push_back(x);
        }


        vector<int>vis(n, 0);
        vector<int>safe(n, false);
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                dfs(i, adj, vis, safe);
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i])ans.push_back(i);
        }
      return ans; 
    }
};