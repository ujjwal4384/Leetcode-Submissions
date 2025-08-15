class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
         vector<vector<int>>adj(n); 
         for(auto x:v){
            adj[x[1]].push_back(x[0]);
         }

         map<int,int>indegree;

         for(auto x: adj){
            for(auto y:x){
                indegree[y]++;
            }
         }

         queue<int>q;   
         for(int i=0; i<n ;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
         }

         vector<int>res;
         while(!q.empty()){
              int node = q.front();
              q.pop();
              res.push_back(node);
              for(auto x: adj[node]){
                 indegree[x]--;
                 if(indegree[x] ==0){
                    q.push(x);
                 }
              }
         }

         return res.size() == n;    
    }
};