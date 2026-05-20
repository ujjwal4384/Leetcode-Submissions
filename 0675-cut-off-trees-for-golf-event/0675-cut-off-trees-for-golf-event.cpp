class Solution {
private:
    pair<int,int>nbs[4] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}}; 
    int bfs(pair<int,int>&src, pair<int,int>&dst, vector<vector<int>>& forest){
            int m = forest.size();
            int n = forest[0].size();
            vector<vector<bool>>visited(m, vector<bool>(n, false));
            queue<pair<int,int>>q;
            q.push(src);
            visited[src.first][src.second] = true;
            int steps = 0;
            while(!q.empty()){
                   int sz = q.size();
                   while(sz--){
                       pair<int,int>node = q.front(); q.pop();
                       if(node==dst) return steps;
                       for(auto& nb: nbs){
                           int nx = node.first + nb.first;
                           int ny = node.second + nb.second;
                           if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && forest[nx][ny] >= 1){
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                           }
                       } 
                   }
                   steps++;
            }
         return -1;   
    }     
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n =forest[0].size();
        auto comp = [](const vector<int>& t1, const vector<int>& t2){
            return t1[0] < t2[0];
        };

        vector<vector<int>>sequences;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(forest[i][j] > 1)
                    sequences.push_back({forest[i][j], i, j});
            }
        }
        sort(sequences.begin(), sequences.end(), comp);

        int totalSteps = 0;
        pair<int,int>src={0,0};
        for(int i=0;i<sequences.size(); i++){
               auto v = sequences[i];
               pair<int,int>dst={v[1],v[2]};
               int steps = bfs(src,dst, forest);
               if(steps == -1) return -1;
               totalSteps += steps;
               src = dst;
        }
        return totalSteps;
    }
};