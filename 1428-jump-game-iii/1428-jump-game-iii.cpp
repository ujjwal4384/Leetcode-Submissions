class Solution {
public:
    bool dfs(int node, vector<int>& arr,vector<bool>&vis){
        if(node< 0 || node>=arr.size() || vis[node]) return false;
        vis[node] = true;

        if(arr[node] == 0) return true;
        
            int nb1 = node  + arr[node];
            int nb2 = node  - arr[node];
        
            bool f1 = dfs(nb1, arr, vis);
        
            bool f2 =dfs(nb2, arr, vis);
        
        

        return f1 || f2 ;
    }
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();

        vector<bool>vis(n, false);

        return dfs(start, arr, vis);
    }
};