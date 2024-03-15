class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         int n=coins.size();
         int* dp = new int[amount+1];
        // sort(coins.begin(), coins.end());
        fill(dp, dp+amount+1, INT_MAX);
        dp[0] = 0;
        for(int amt=1;amt<=amount; amt++){
              for(auto& c : coins){
                  // if(amt-c<0)break;  
                  if(amt-c>=0 && dp[amt-c]!= INT_MAX){
                    dp[amt] = min(dp[amt], 1 + dp[amt-c]);
                     
                  }
              }
         }
        
       return dp[amount]==INT_MAX ? -1 : dp[amount]; 
    }
};