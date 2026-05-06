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
            int last_available_row=n-1;
            for(int i=n-1;i>=0;i--){
              
              //obstacle
              if(res[i][j] == '*'){
                   last_available_row = i-1;
              }
              //stone
              else if(res[i][j] == '#'){
                   res[i][j] = '.';
                   res[last_available_row][j] = '#';
                   last_available_row --;
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