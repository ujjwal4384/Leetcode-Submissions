class Solution {
public:
     long long int f(vector<int>& prices, int i, int type, long long int dp[5001][2], int fee){
        //BASE CASE
        if (i == prices.size() - 1) {
            return (type == 1) ? prices[i] - fee : 0; // Force sell if holding a stock
        }

   

        else if(dp[i][type]!=-1) return dp[i][type];
        // BUY
        if(type==0){
            long long int notBuy= INT_MIN, buy= INT_MIN;
            notBuy = f(prices, i+1, type, dp, fee);
            buy = -1LL* prices[i] + f(prices, i+1, 1-type, dp, fee);
            return dp[i][type]= max(notBuy, buy);
        }
        //SELL
        else if(type==1){
            long long int notSell= INT_MIN, sell=INT_MIN;
            notSell = f(prices, i+1, type, dp, fee);
            sell = prices[i] - fee + f(prices, i+1, 1-type, dp, fee);        
            return dp[i][type]= max(sell, notSell);
        }
      return INT_MIN;
    }
    int maxProfit(vector<int>& prices, int fee) {
          long long int dp[50001][2];
        memset(dp, -1LL, sizeof(dp));
        return (int)f(prices, 0, 0, dp, fee);
    }
};