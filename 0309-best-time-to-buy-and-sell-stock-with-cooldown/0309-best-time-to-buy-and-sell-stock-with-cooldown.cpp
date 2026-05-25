class Solution {
    int f(int i, bool canBuy, vector<int>& prices, int dp[5001][2]){
        if(i>=prices.size()) return 0;
    
        if(i==prices.size()-1){
            if(!canBuy)
                return prices.back();
            return 0;    
        }
        
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        if(canBuy){
            int actualyBuy =  (-prices[i] + f(i+1, 0, prices, dp) ) ;
            int skipsBuying = f(i+1, 1, prices, dp);
            return dp[i][canBuy] = max(actualyBuy, skipsBuying);
        }else{
            
            int actualySell = prices[i] + f(i+2, 1, prices, dp);
            int skipsSelling = f(i+1, 0, prices, dp);
            return dp[i][canBuy] = max(actualySell, skipsSelling);
        }
        return 0;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int dp[5001][2];
        memset(dp, -1, sizeof(dp));
        return max(0, f(0,  true, prices, dp));
    }
};