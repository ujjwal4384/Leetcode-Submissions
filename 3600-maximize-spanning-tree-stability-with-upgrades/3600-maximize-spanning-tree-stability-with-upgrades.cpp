class Dsu{
  private:
   vector<int>par;
   vector<int>sz;
   int n;
  public:
  Dsu(int m){
      n = m;
      par.resize(n+1);
      sz.resize(n+1);
      for(int i=0;i<=n;i++){
          par[i] = i;
          sz[i] = 0;
      }
  }
  
  void _union(int u, int v){
      if(u==v) return;
      int parU = findPar(u);
      int parV = findPar(v);
      
      if(parU == parV) return;
      
      if(sz[parU] > sz[parV]){
          par[parV] = parU;
      }else if(sz[parU] < sz[parV]){
          par[parU] = parV;
      }else{
          par[parV] = parU;
          sz[parU] ++;
      }
  }
  
  
  int findPar(int u){
      if(par[u] == u) return u;
      return par[u] = findPar(par[u]);
  }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
       //step-1: add all mujst edges.
       Dsu dsuObj(n);
       int minStrengthFromMustAddEdges = INT_MAX;
       for(auto e:edges) {
          int u = e[0], v= e[1], s=e[2], m=e[3];
          if(m==0) continue;
          if(dsuObj.findPar(u) == dsuObj.findPar(v))return -1; //cycle detected
          dsuObj._union(u, v);
          minStrengthFromMustAddEdges = min(minStrengthFromMustAddEdges, s);
       }
            
       //Binary search on strength
       int l = 0, r= minStrengthFromMustAddEdges;
       int ans = -1;
       while(l<=r){
          int m = l+ ((r-l)>>1) ;
          Dsu curDsuObj = dsuObj;
          int costUsed = 0;
         // Pass 1: Add all Cost 0 edges first
          for(auto& e : edges){
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if(must == 1) continue; 
            if(s >= m) { // Cost 0
                if(curDsuObj.findPar(u) != curDsuObj.findPar(v)) {
                    curDsuObj._union(u, v);
                }
            }
          } 

          // Pass 2: Add Cost 1 edges (Only if needed)
          for(auto& e : edges){
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if(must == 1) continue; 
            if(s < m && 2LL * s >= m) { // Cost 1
                if(curDsuObj.findPar(u) != curDsuObj.findPar(v)) {
                    curDsuObj._union(u, v);
                    costUsed++;
                }
            }
          }
          //check if all are connected nodes.
          bool allNodesConnected = true;
          for(int i=1;i<n;i++){
            if(curDsuObj.findPar(i)!=curDsuObj.findPar(i-1)){
                allNodesConnected = false;
                break;
            }
          }
          if(costUsed <= k && allNodesConnected == true){
            ans = m;
            l = m + 1;
          }else {
            r = m -1;    
          }
    
       }
       return ans;
    }
};