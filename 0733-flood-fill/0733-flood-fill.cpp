class Solution {
public:
    int isValid(int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    pair<int,int> nbs[4] = {{-1,0},{1,0},{0,-1},{0, 1}};
    void dfs(int x, int y, vector<vector<int>>& image, int c, int& color, vector<vector<bool>>&vis){
         vis[x][y] = true;
         image[x][y] = color;
         for(int i=0;i<4; i++){
            int nx = nbs[i].first + x;
            int ny = nbs[i].second + y;

            if(isValid(nx, ny, image.size(), image[0].size())  && image[nx][ny]==c && !vis[nx][ny]){
                dfs(nx, ny, image, c, color, vis);
            }
         }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int c = image[sr][sc];
        int m = image.size();
        int n= image[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        dfs(sr, sc, image, image[sr][sc], color, vis);

        return image;
    }
};