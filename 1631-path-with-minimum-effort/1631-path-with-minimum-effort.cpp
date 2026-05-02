class Solution {
    pair<int,int>nbs[4] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    bool isPossible(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>&vis, int& mid){
        vis[i][j] = true;
        int m = heights.size(), n= heights[0].size(); 
        if(i== m-1 && j==n-1){
            return true;
        }
        for(auto nb:nbs){
            int nx = i+ nb.first;
            int ny = j+ nb.second;
            if(nx>=0 && nx< m && ny>=0 && ny< n && !vis[nx][ny] && abs(heights[nx][ny] - heights[i][j]) <= mid){
                  if(isPossible(nx, ny, heights,vis, mid)) return true;
            }
        }
       return false; 
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n= heights[0].size(); 
        int ans = 1e6;
        int l =0, r = 1e6;
        while(l<=r){
            int mid = l +((r-l)>>1);
            vector<vector<bool>>vis(m, vector<bool>(n, false));
            if(isPossible(0, 0, heights, vis, mid)){
                 ans = mid;
                 r = mid-1;
            }else{
                l= mid+1;
            }
        }

        return ans;
    }
};