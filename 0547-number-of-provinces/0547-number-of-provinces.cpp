class dsu{
    private:
        int n;
        vector<int>par;
        vector<int>sz;
        
    public:
    dsu(int n){
        this->n = n;
        par.resize(n+1);
        sz.resize(n+1, 0);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    
    void _union(int node1, int node2){
        if(node1==node2) return ;
        
        int par1 = _findPar(node1);
        
        int par2 = _findPar(node2);
        
        if(par1 == par2) return;
        
        if(sz[par1] > sz[par2]){
            par[par2] = par1; 
            
        }
        else if(sz[par2] > sz[par1]){
            par[par1] = par2;      
        }else{
            par[par2] = par1; 
            sz[par1]++;
        }
    
    }
    
    int _findPar(int node){
        if(par[node] == node) return  node;
        return par[node] = _findPar(par[node]);
    }
    
    bool _isSameParent(int node1, int node2){
        if(node1==node2) return true;
        
        int par1 = _findPar(node1);
        
        int par2 = _findPar(node2);
        
        if(par1 == par2) return true;
        return false;
    }
    
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& v) {
        int m = v.size();
        
        
        
        dsu * obj = new dsu(m);

        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                if(v[i][j]){
                    if(! obj->_isSameParent(i, j)){
                        obj->_union(i, j);
                    }
                }
            }
        }

        set<int>s ;
        for(int i=0;i<m;i++){
            int p = obj->_findPar(i);
            s.insert(p);
        }

        return s.size();
    }
};