class Solution {
public:
//0-1bfs
    bool isValid(int nx, int ny, int m, int n ){
        return nx>=0 && nx<m && ny>=0 && ny<n;
    }
    int minCost(vector<vector<int>>& grid) {
        int m =grid.size();
        int n=grid[0].size();

        map<pair<int,int>, vector<pair < pair<int,int>,int>> > mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    mp[{i,j}].push_back({{i,j+1},0});
                    mp[{i,j}].push_back({{i,j-1},1});
                    mp[{i,j}].push_back({{i+1,j},1});
                    mp[{i,j}].push_back({{i-1,j},1});    
                }
                else if(grid[i][j] ==2){
                    mp[{i,j}].push_back({{i,j+1},1});
                    mp[{i,j}].push_back({{i,j-1},0});
                    mp[{i,j}].push_back({{i+1,j},1});
                    mp[{i,j}].push_back({{i-1,j},1});
                }
                else if(grid[i][j] ==3){
                    mp[{i,j}].push_back({{i,j-1},1});
                    mp[{i,j}].push_back({{i,j+1},1});
                    mp[{i,j}].push_back({{i+1,j},0});
                    mp[{i,j}].push_back({{i-1,j},1});
                }
                else if(grid[i][j] ==4){
                    mp[{i,j}].push_back({{i,j-1},1});
                    mp[{i,j}].push_back({{i,j+1},1});
                    mp[{i,j}].push_back({{i+1,j},1});
                    mp[{i,j}].push_back({{i-1,j},0});
                }
            }

        }

        // for(auto p:mp){
        //     int x = p.first.first;
        //     int y= p.first.second;
        //     vector<pair < pair<int,int>,int>> v=p.second;
        //     cout<<x<<" "<<y<<" :\n";
        //     for(auto k:v){
        //         cout<<k.first.first<<","<<k.first.second<<", w="<<k.second<<endl;
        //     }

        // }

        deque< pair<int,pair<int,int>> >dq;
       
        dq.push_front({0, {0,0}});
        vector<vector<int>>cost(m, vector<int>(n, 1e8));
        cost[0][0] = 0;
        

        while(!dq.empty()){
            auto it = dq.front();
            dq.pop_front();
            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;

            for(auto p: mp[{x,y}]){
                
                int nx = p.first.first;
                int ny = p.first.second;
                int w = p.second;
             
                if(isValid(nx, ny, m, n)  && d+ w < cost[nx][ny] ){
                     cost[nx][ny] = d+w;
                   
                     if(w==0){
                        dq.push_front({cost[nx][ny], {nx,ny}});
                     }else{
                        dq.push_back({cost[nx][ny], {nx,ny}});        
                     }
                }    
            }
        }

        return cost[m-1][n-1];
        
    }
};