class Solution {
public:
    bool isValid(int r, int c, int n, vector<vector<char>>&v){
        //horizontal
        for(int j=0;j<n;j++){
            if(v[r][j] == 'Q') return false;
        }

        //vertical
        for(int i=0;i<n;i++){
            if(v[i][c] == 'Q') return false;
        }

        //top-left
        for(int i=r,j=c; i>=0 && j>=0; i--,j--){
            if(v[i][j] == 'Q') return false;
        }


        //top-right
        for(int i=r,j=c; i>=0 && j<n; i--,j++){
            if(v[i][j] == 'Q') return false;
        }

        //bottom-left
        for(int i=r,j=c; i<n && j>=0; i++,j--){
            if(v[i][j] == 'Q') return false;
        }


        //bottom-right
        for(int i=r,j=c; i<n && j<n; i++,j++){
            if(v[i][j] == 'Q') return false;
        }

        return true;
    }

    void f(int row, int n, vector<vector<char>>&v, vector<vector<string>>&res){
       //BASE CASE
       if(row==n){
        
        vector<string>temp;
        for(auto y:v){
            string s="";
            for(auto ch:y){
                s += ch;
            }
            temp.push_back(s);
        }
        res.push_back(temp);
        return;
       } 

       for(int col =0; col<n; col++ ){
          
          bool flag = isValid(row, col,n,  v);
          if(flag){
               v[row][col] = 'Q';
               f(row+1, n, v, res); 
               v[row][col] = '.';
          }  
          
       } 

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<vector<char>>v(n, vector<char>(n, '.'));
        f(0, n, v, res);
        return res;
    }
};