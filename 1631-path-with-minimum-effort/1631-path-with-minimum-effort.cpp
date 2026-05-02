class Solution {
    pair<int,int>nbs[4] = {{-1,0},{1,0},{0,-1},{0,1}};
    int INF = 1e8;
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
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dis(m, vector<int>(n, INF));
        dis[0][0] = 0;
        pq.push({0, {0,0}});
        while(!pq.empty()){
                auto [cost, pos] = pq.top();
                auto [i, j] = pos;
                pq.pop();
                if(i == m-1 && j == n-1) return cost;
                for(auto &nb: nbs){
                    int nx = i+nb.first, ny = j+nb.second;
                    if(nx>=0 && nx< m && ny>=0 && ny< n){
                        int edgeWeight = abs(heights[nx][ny] - heights[i][j]);
                        int newCost = max(cost, edgeWeight);
                        if(dis[nx][ny] > newCost){
                            dis[nx][ny] = newCost;
                            pq.push({dis[nx][ny], {nx, ny}});
                        } 
                        
                    }
                }
        }    

        return 0;
    }
};