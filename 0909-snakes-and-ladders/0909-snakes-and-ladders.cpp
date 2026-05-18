class Solution {
public:
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int cell = n*n;
        int mini = INT_MAX;
        map<int,int>edge;
        int row = n-1;
        int dir =1;
        int num = 1;
        while(row>=0){
            if(dir){
                //move right
                for(int j=0;j<n;j++){
                        if(board[row][j] != -1) {
                            edge[num] = board[row][j];
                                 
                        }
                        num++;
                }
            }else{
                for(int j=n-1;j>=0;j--){
                        if(board[row][j] != -1) {
                            edge[num] = board[row][j];
                            
                        }
                        num++;     
                }
            }
            row--;
            dir = 1-dir;
        }


        queue<int>q;
        int steps = 0;
        q.push(1);
        vector<bool>vis(n*n+1, false);
       vis[1] = true;
       while(!q.empty()) {
        int sz = q.size();
            while(sz--){
                int node = q.front()  ; 
                q.pop();
                if(node == n*n) return steps;
                
                for(int k=1;k<=6;k++){
                    int adjNode = node + k;
                    int newNode = edge.count(adjNode) ? edge[adjNode] : adjNode ;    
                    if(newNode > n*n || vis[newNode]) continue;
                    vis[newNode] = true;
                    q.push(newNode);
                }
            }
            if(sz)steps++;
       }
      return -1;
    }
};