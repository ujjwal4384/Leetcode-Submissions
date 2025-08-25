class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        
        map<int,int>edge;
        int row = n-1, dir = 1;
        int num = 1;
        while(row >=0){
            if(dir%2){
                // go right
                for(int j=0;j<n;j++){
                    if(board[row][j] != -1){
                        edge[num] = board[row][j];
                    }
                    num++;
                }         
            }else{
                // go left
                for(int j=n-1;j>=0;j--){
                    if(board[row][j] != -1){
                        edge[num] = board[row][j];
                    }
                    num++;
                }
            }
            dir++;
            row--;
        }

        int maxi = n*n;
        if(edge.find(maxi) != edge.end()) return -1;

        queue<int>q;
        q.push(1);
        vector<bool>vis(maxi+1, false);
        vis[1] = true;
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                if(node == maxi) return steps;
                for(int k=1;k<=6;k++){
                    int new_node =  node + k;
                    bool isEdgePresent = (edge.find(new_node) != edge.end());
                    new_node = isEdgePresent ? edge[new_node] : new_node;
                    if(new_node >maxi || vis[new_node])continue;            
                    vis[new_node] = true;
                    q.push(new_node);
        
                }
            }
            steps++;
        }

    return -1;
        
    }
};