class Solution {
int m,n;    
vector<vector<int>>dp;
public:
    int f(int i, int j, vector<vector<int>>& dungeon){
        if(i==m-1 && j==n-1){
            return dungeon[i][j] >=0 ? 0: dungeon[i][j];
        }
        if(i>=m || j>=n) return INT_MIN;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int way1, way2= INT_MIN;
        way1= f(i+1, j, dungeon);
        way2= f(i,j+1, dungeon);
        int optimal = max(way1, way2) + dungeon[i][j];
        if(optimal>=0) return dp[i][j] = 0;
        
        return dp[i][j] = optimal;
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
       
        dp.clear();
       
        m=dungeon.size(), n=dungeon[0].size();
         dp = vector<vector<int>>(m, vector<int>(n, INT_MIN));
        return -1*f(0,0, dungeon)+1;
    }
};


//i,j tak aane me need?: i-1,j tak ki need=10. i-1, j. 5 