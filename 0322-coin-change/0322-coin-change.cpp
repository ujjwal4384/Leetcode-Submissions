class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<long long>dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int amt = 1; amt<=amount; amt++){
            for(int i=0;i<n; i++){
                  if(amt-coins[i]>=0){
                    long long cur = 1 + dp[amt-coins[i]];
                    dp[amt] = min(dp[amt], cur);
                  }
            }
        }
       return dp[amount] == INT_MAX ?  -1 : dp[amount] ;
    }
};