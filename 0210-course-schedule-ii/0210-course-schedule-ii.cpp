class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>>& prerequisites){
        vector<vector<int>>adj(n);
        for(auto &p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        
        map<int, int>indegree;
        
        
        for(int i=0;i<n;i++){
            for(auto&x:adj[i]){
               indegree[x]++;   
             }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>order;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                order.push_back(node);
                for(auto&x:adj[node]){
                    indegree[x]--;
                    if(indegree[x]==0){
                        q.push(x);
                    }
                }

            }
        }

       return order; 
    }
   
   bool dfs(int i, vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&pathVis, vector<int>&res){
     vis[i] = true;
     pathVis[i] = true;
      
        for(auto x: adj[i]){
            if(vis[x]){
                if(pathVis[x]) return true; //cycle detected
                else continue;
            }
            else{
                if(dfs(x, adj, vis, pathVis, res)) return true;
            }
        }

      pathVis[i] = false;
      res.push_back(i);  
      return false;  
   }
   
   vector<int> dfsSolve(int n, vector<vector<int>>& prerequisites){
        vector<vector<int>>adj(n);
        
        for(auto &p: prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        vector<bool>vis(n, false);
        vector<bool>pathVis(n, false);
        vector<int>res;
        for(int i=0 ;i<n; i++){
            
            if(!vis[i]){
                //cycle found
                if(dfs(i, adj, vis, pathVis, res)) return res;
            }
        }
        
        
        return res; 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //vector<int> order = topoSort(numCourses, prerequisites); 
        vector<int> order = dfsSolve(numCourses, prerequisites); 
        if(order.size()!=numCourses) return {};
        
        return order;
    }
};