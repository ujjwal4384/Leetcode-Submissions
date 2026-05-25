class Solution {
    int f(int i, int tx, bool canBuy, vector<int>& prices, int dp[1001][101][2]){
        if(tx==0) return 0;
    
        if(i==prices.size()-1){
            if(!canBuy)
                return prices.back();
            return 0;    
        }
        
        if(dp[i][tx][canBuy] != -1) return dp[i][tx][canBuy];
        if(canBuy){
            int actualyBuy = tx>0 ? (-prices[i] + f(i+1, tx, 0, prices, dp) ) : 0;
            int skipsBuying = f(i+1, tx, 1, prices, dp);
            return dp[i][tx][canBuy] = max(actualyBuy, skipsBuying);
        }else{
            
            int actualySell = prices[i] + f(i+1, tx-1, 1, prices, dp);
            int skipsSelling = f(i+1, tx, 0, prices, dp);
            return dp[i][tx][canBuy] = max(actualySell, skipsSelling);
        }
        return 0;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int tx = k;
        bool canBuy = true;
        int dp[1001][101][2];
        memset(dp, -1, sizeof(dp));
        return max(0, f(0, tx, canBuy, prices, dp));
    }
};