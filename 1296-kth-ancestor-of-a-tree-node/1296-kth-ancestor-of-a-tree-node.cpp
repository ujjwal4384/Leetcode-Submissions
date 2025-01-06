class TreeAncestor {
    vector<vector<int>>table;
    int MAX = 17;
public:
    TreeAncestor(int n, vector<int>& parent) {
        table.resize(n,vector<int>(MAX+1, -1));
        
        for(int i=0;i<n;i++){
            table[i][0] = parent[i];
        }

        for(int par = 1; par <= MAX ; par++){
            for(int i=0;i<n;i++){
                int parMinusOne = table[i][par-1];
                if(parMinusOne==-1)
                      table[i][par] = -1;   
                else 
                      table[i][par] = table[parMinusOne][par-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i=0;i<=MAX; i++){
            if( (1<<i) & k){
               if(node != -1) node = table[node][i];
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */