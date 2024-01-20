class Solution {
public:
    bool isValid(vector<string>&vs, int r, int c, int n){
       
        //row
        for(int j=0;j<=c;j++){
            if(vs[r][j]=='Q')return false;
        } 
        //col
        for(int i=0;i<=r;i++){
            if(vs[i][c]=='Q')return false;
        } 
        //top-left diag
        for(int i=r,j=c;i>=0 && j>=0; i--,j--){
            if(vs[i][j]=='Q')return false;
        }
        // top-right
        for(int i=r,j=c;i>=0 && j<n ;i--,j++){
            if(vs[i][j]=='Q')return false;
        }
       
            
        
        return true;
    }
    void f(int row,  vector<vector<string>>&res, vector<string>&vs, int n){
       
        if(row==n){
             res.push_back(vs);
             return;
        }
      
            for(int j=0;j<n;j++){
                    if(isValid(vs, row, j, n)){
                       
                        vs[row][j]='Q';
                         f(row+1, res, vs, n);
                        vs[row][j]='.';
                    }
            }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        string t(n,'.');
        vector<string>vs(n, t);
        
        f(0, res, vs, n);
       return res; 
    }
};