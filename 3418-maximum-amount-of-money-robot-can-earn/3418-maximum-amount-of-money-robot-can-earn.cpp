class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
       
        int dp[501][501][3] ={};
        for(int i=0;i<501;i++)for(int j=0;j<501;j++)for(int k=0;k<3;k++)dp[i][j][k]=-1e7;
        int m=coins.size(), n= coins[0].size();
        
        if(coins[0][0] < 0) dp[0][0][1] = 0;
        dp[0][0][2] = coins[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                //from top
                if(i-1>=0){
                    int a = dp[i-1][j][0];
                    int b = dp[i-1][j][1];
                    int c = dp[i-1][j][2];
                    if(coins[i][j]<0){
                        dp[i][j][0] = max(a + coins[i][j], b);
                        dp[i][j][1] = max(b + coins[i][j], c);
                        dp[i][j][2] = c + coins[i][j];
                    }
                    else {
                        dp[i][j][0] = a + coins[i][j];
                        dp[i][j][1] = b + coins[i][j];
                        dp[i][j][2] = c + coins[i][j];
                    }

                }

                //from left
                if(j-1>=0){
                    int a = dp[i][j-1][0];
                    int b = dp[i][j-1][1];
                    int c = dp[i][j-1][2];
                    if(coins[i][j]<0){
                        dp[i][j][0] = max({dp[i][j][0], a + coins[i][j], b});
                        dp[i][j][1] = max({dp[i][j][1], b + coins[i][j], c});
                        dp[i][j][2] = max({dp[i][j][2], c + coins[i][j]});
                    }
                    else {
                        dp[i][j][0] = max({dp[i][j][0], a + coins[i][j]});
                        dp[i][j][1] = max({dp[i][j][1], b + coins[i][j]});
                        dp[i][j][2] = max({dp[i][j][2], c + coins[i][j]});
                    }

                }

            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};