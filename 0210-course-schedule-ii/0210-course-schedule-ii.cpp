class Solution {
public:
    void topoSort(int n, vector<vector<int>>& v, vector<int>&order){
        vector<vector<int>>adj(n);
        for(int i=0;i<v.size();i++){
            int x = v[i][0],y=v[i][1];  
            adj[y].push_back(x);
        }
       
        queue<int>q;
        map<int,int>indegree;
        for(int i=0;i<n;i++){
            for(auto&x:adj[i]){
                 indegree[x]++;
            }
        }
      
    
        for(int node=0;node<n;node++){
            if(indegree[node]==0){
                q.push(node);
              
            }
        }
       
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                order.push_back(node);
                q.pop();
                for(auto&x:adj[node]){
                    indegree[x]--;
                    if(indegree[x]==0){
                        q.push(x);
                    }
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& v) {
      vector<int>order;
       topoSort(numCourses, v, order);
      
        if(order.size()!=numCourses) return {};
        return order;
        
    }
};