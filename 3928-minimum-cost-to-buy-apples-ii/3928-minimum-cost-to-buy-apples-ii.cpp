#define ll long long
class Solution {
private:
   vector<long long> dijkstra(int startNode,vector<vector<pair<ll,ll>>>&adj){
      int n = adj.size();
      vector<long long>dis(n, 1e15);
      dis[startNode]  = 0;
      priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
      pq.push({0, startNode});
      while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second; long long w = top.first;
            for(auto nb: adj[node]){
                ll newNode = nb.first; ll d = nb.second;
                if(dis[newNode] == 1e12 || dis[newNode] > d + w){
                    dis[newNode] = d + w;
                    pq.push({dis[newNode], newNode});
                }
            }
      }
      return dis;
   }    
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
     //two independent graph problems of shortest path
     //forward path frist: find min distance from i to j empty  (weight = cost)
     //return path then : find min distance from i,j with loaded apples  (weight= cost*tax)  
     //now for each nodei -> check potential purchases for each j shops. if purchased from j ship then = empty_d[j] + price[j] + loaded_d[j] 
     //its sum shoould be mimimum across j. which=ever is minimum, we will take that for that i.


     //multisourfce dijsktra for two subproblems.
     
       vector<vector<pair<ll,ll>>>emptyAdj(n);
       vector<vector<pair<ll,ll>>>loadedAdj(n);
       for(auto road:roads){
            int u = road[0], v= road[1], cost = road[2], tax = road[3];
            emptyAdj[u].push_back({v, cost});
            emptyAdj[v].push_back({u, cost});

            loadedAdj[u].push_back({v, 1LL*cost*tax});
            loadedAdj[v].push_back({u, 1LL*cost*tax});
       }

       vector<ll>ans(n);

       for(int i=0;i<n;i++)ans[i] = prices[i];
       for(int i=0;i<n; i++){
              vector<long long>disEmpty = dijkstra(i, emptyAdj);
              vector<long long>disLoaded = dijkstra(i, loadedAdj);
               for(int j=0;j<n;j++){
                  if(j==i)continue;
                  if(disEmpty[j] != 1e12) 
                     ans[i] = min(ans[i], (disEmpty[j] + prices[j] + disLoaded[j]) );
               }    
       }
       vector<int>ans2(n);
       for(int i=0;i<n;i++)ans2[i] = ans[i];
       return ans2; 
    }
};