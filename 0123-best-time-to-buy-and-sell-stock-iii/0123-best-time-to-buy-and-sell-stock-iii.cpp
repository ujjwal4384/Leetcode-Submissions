class Solution {
    int f(int i, int tx, bool canBuy, vector<int>& prices, int dp[100001][3][2]){
        if(tx<0) return 0;
        if(i>=prices.size()){
            return 0;
        }
        if(i==prices.size()-1 && !canBuy){
            return prices.back();
        }
        if(dp[i][tx][canBuy] != -1) return dp[i][tx][canBuy];
        if(canBuy){
            int actualyBuy = tx>0 ? (-prices[i] + f(i+1, tx-1, 0, prices, dp) ) : 0;
            int skipsBuying = f(i+1, tx, 1, prices, dp);
            return dp[i][tx][canBuy] = max(actualyBuy, skipsBuying);
        }else{
            
            int actualySell = prices[i] + f(i+1, tx, 1, prices, dp);
            int skipsSelling = f(i+1, tx, 0, prices, dp);
            return dp[i][tx][canBuy] = max(actualySell, skipsSelling);
        }
        return 0;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int tx = 2;
        bool canBuy = true;
        int dp[100001][3][2];
        memset(dp, -1, sizeof(dp));
        return max(0, f(0, tx, canBuy, prices, dp));
    }
};