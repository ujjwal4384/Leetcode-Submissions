class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n= boxGrid[0].size();
        vector<vector<char>>res(n, vector<char>(m, ' '));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[j][m-1-i] = boxGrid[i][j] ;
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<res[i][j]<<" ";
        //     }cout<<endl;
        // }cout<<"----------------"<<endl<<endl;

        for(int j=0;j<m;j++){
            queue<int>q;
            for(int i=n-1;i>=0;i--){
                //empty
              if(res[i][j] == '.'){
                    q.push(i);
              }
              //obstacle
              else if(res[i][j] == '*'){
                    //flush
                    while(!q.empty())q.pop();
              }
              //stone
              else{
                   if(q.empty())continue;
                   int idash =  q.front();
                   q.pop();
                   res[idash][j] = res[i][j];
                   res[i][j] = '.';
                   q.push(i);
              }   
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<res[i][j]<<" ";
        //     }cout<<endl;
        // }
        return res;
    }
};