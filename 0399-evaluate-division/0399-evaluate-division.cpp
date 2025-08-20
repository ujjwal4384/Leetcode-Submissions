class Solution {
public:
    double traverse(int src, int dst, vector<vector<pair<int,double>>>& adj, unordered_map<int,bool>&mp){
      
        mp[src] = true;
        if(src == dst) return 1.0;
        
        for(auto p:adj[src]){
            int adjNode = p.first;
            double val = p.second;
           
            if(mp.find(adjNode)==mp.end()){
                  double k = traverse(adjNode, dst, adj, mp);
                    
                  if(k!=-1.0){
                    return val * k;
                  }
            }else{
                cout<<endl;
            }
        }
        return -1.0;
    }

    

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {        
        int counter = 0;
        map<string,bool>vis;
        map<string, int>hash;
         for(int i=0;i<equations.size(); i++){
            vector<string> equation = equations[i];
            string strA = equation[0];
            string strB = equation[1];
            if(vis[strA]==false){
                vis[strA] = true;
                counter++;
                hash[strA] = counter;
            }
            if(vis[strB]==false){
                vis[strB] = true;
                counter++;
                hash[strB] = counter;
            }
         }

         vector<vector<pair<int,double>>>adj(counter+1);
        for(int i=0;i<equations.size(); i++){
            vector<string> equation = equations[i];
            string strA = equation[0];
            string strB = equation[1];
            int nodeA = hash[strA];
            int nodeB = hash[strB];
            double value = values[i];
            adj[nodeA].push_back({nodeB, value});
            adj[nodeB].push_back({nodeA, 1.0/value});
        }
      
        
        vector<double>v;
        for(auto q:queries){
            string strA = q[0];
            string strB = q[1];
            
            if(hash.find(strA)==hash.end() || hash.find(strB)==hash.end()){
                   v.push_back(-1);
                   continue;
            }
            int nodeA = hash[strA];
            int nodeB = hash[strB];
            unordered_map<int,bool>mp;
            v.push_back(traverse(nodeA, nodeB, adj, mp));
            mp.clear();
        }

        return v;
    }
};