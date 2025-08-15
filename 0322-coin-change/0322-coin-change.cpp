class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<int>dp(amount+1,amount+1);
        dp[0] =0;
       
        for(int amt=0;amt<=amount;amt++){
            for(int i=0;i<n;i++){
                if(amt>=coins[i]){
                    dp[amt] = min(dp[amt],1 + dp[amt-coins[i]]);
                }
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};