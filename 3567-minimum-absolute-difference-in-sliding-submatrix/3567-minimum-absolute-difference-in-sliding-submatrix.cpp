class Solution {
public:
   int getMinAbsDiff(set<int>&s){
  
       if(s.size()==1) return 0;
       auto it = s.begin();
       it++;
       int mini = INT_MAX;
       while(it != s.end()){
            int a = *it;
            int b = *prev(it);
            mini = min(mini, abs(b-a));
            it++;
       }
       return mini;
   }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n= grid[0].size();

        vector<vector<int>>ans(m-k+1, vector<int>(n-k+1, 0));
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                  set<int>s;  
                  for(int p=i;p<i+k;p++){
                     for(int q=j;q<j+k;q++){
                          s.insert(grid[p][q]);
                     }
                  }
                  ans[i][j] = getMinAbsDiff(s);
                  s.clear();
            }
        }
         
        return ans;
    }
};