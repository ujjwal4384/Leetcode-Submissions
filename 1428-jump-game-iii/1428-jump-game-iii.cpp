class Solution {
public:
    bool dfs(int node, vector<int>& arr,vector<bool>&vis){
        
        vis[node] = true;

        if(arr[node] == 0) return true;
        
        int nb1 = node  + arr[node];
        int nb2 = node  - arr[node];
        
        if(nb1>=0 && nb1< arr.size() && !vis[nb1]){
            bool f = dfs(nb1, arr, vis);
            if(f) return true;
        }

        if(nb2>=0 && nb2< arr.size()  && !vis[nb2]){
            bool f =dfs(nb2, arr, vis);
            if(f) return true;
        }

        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();

        vector<bool>vis(n, false);

        return dfs(start, arr, vis);
    }
};