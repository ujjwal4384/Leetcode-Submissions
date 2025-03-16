class Solution {
public:
    int f(vector<int>& prices, int i, int type, int tx,int dp[][2][101] ){
        //BASE CASE
        if(tx==0){
            return 0;
        }
        else if(i==prices.size()-1){
            if(type==0){
                //donot buy
                return 0;
            }else{
                //must sell.
                return prices.back();
            }
        }
        else if(i>=prices.size()){
            return INT_MIN;
        }

        else if(dp[i][type][tx]!=-1) return dp[i][type][tx];
        // BUY
        if(type==0){
            int notBuy= INT_MIN, buy= INT_MIN;
            notBuy = f(prices, i+1, type, tx, dp);
            buy = -1* prices[i] + f(prices, i+1, 1-type, tx, dp);
            return dp[i][type][tx]= max(notBuy, buy);
        }
        //SELL
        else if(type==1){
            int notSell= INT_MIN, sell=INT_MIN;
            notSell = f(prices, i+1, type, tx, dp);
            sell = prices[i] + f(prices, i+1, 1-type, tx-1, dp);        
            return dp[i][type][tx]= max(sell, notSell);
        }
      return INT_MIN;
    }
    int maxProfit(int k, vector<int>& prices) {
        int dp[1001][2][101];
        memset(dp, -1, sizeof(dp));

      return max(0, f(prices, 0 , 0, k, dp));
    }
};