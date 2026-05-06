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
            set<int, greater<int>>available_row;
            for(int i=n-1;i>=0;i--){
                //empty
              if(res[i][j] == '.'){
                    available_row.insert(i);
              }
              //obstacle
              else if(res[i][j] == '*'){
                    available_row.clear();
              }
              //stone
              else{
                   if(available_row.empty())continue;
                   int idash =  *available_row.begin();
                   available_row.erase(available_row.begin());
                   res[idash][j] = res[i][j];
                   res[i][j] = '.';
                   available_row.insert(i);
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