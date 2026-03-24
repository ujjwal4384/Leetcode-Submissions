class Solution {
    int MOD = 12345;
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long mul = 1;
        vector<vector<int>>suff(m, vector<int>(n, 0));
        for(int i=m-1; i>=0 ;i--){
            for(int j=n-1;j>=0;j--){
                 mul = (mul * grid[i][j]%MOD + MOD)%MOD ;
                 suff[i][j] = mul;
            }
        }
        vector<vector<int>>ans(m, vector<int>(n, 0));
        long long p =1 ;
        for(int i=0; i<m ;i++){
            for(int j=0;j<n;j++){
                 int s = j+1<n ?suff[i][j+1]: i+1<m ? suff[i+1][0]: 1; 
                 ans[i][j] = (p * s%MOD + MOD)%MOD;
                 p = (p*grid[i][j]%MOD +MOD)%MOD;
            }
        }
        return ans;
    }
};