class Solution {
public:
   int getMinAbsDiff(multiset<int>&ms){
       if(ms.size()==1) return 0;
       auto it = ms.begin();
       it++;
       int mini = INT_MAX;
       while(it != ms.end()){
            int a = *it;
            int b = *prev(it);
            if(a!=b)
              mini = min(mini, abs(b-a));
            it++;
       }
       return mini == INT_MAX ? 0 : mini;
   }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n= grid[0].size();

        vector<vector<int>>ans(m-k+1, vector<int>(n-k+1, 0));
        for(int row = 0; row<m-k+1; row++){
            //load first k*k submatrix
            multiset<int>ms;
            for(int i=row;i<row+k;i++){
                for(int j=0;j<k;j++ ){
                    ms.insert(grid[i][j]);
                }
            }
            ans[row][0] = getMinAbsDiff(ms);
            //sliding window
            for(int col=k;col<n;col++){
                //remove elements of col-k, add elements of col;
                for(int i=row;i<row+k;i++){
                    auto it = ms.find(grid[i][col-k]);
                    ms.erase(it);
                    ms.insert(grid[i][col]);
                }
                ans[row][col-k+1] = getMinAbsDiff(ms);
            }
        }
         
        return ans;
    }
};