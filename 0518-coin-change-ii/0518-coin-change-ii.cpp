class Solution {
public:
    int change(int amount, vector<int>& coins) {
       int n = coins.size();
       
       
       vector<unsigned int>dp(amount+1, 0);
       dp[0] = 1;
       for(int i=0;i<n;i++){
        
           for(int amt =coins[i]; amt<=amount; amt++){
                 dp[amt] += dp[amt- coins[i]];
           }
       }
      return (int)dp[amount] ;

    }
};