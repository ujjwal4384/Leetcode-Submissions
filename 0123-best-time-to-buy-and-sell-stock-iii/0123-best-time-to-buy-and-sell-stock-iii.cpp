#define ll long long
class Solution {
public:
    ll f(int i, int op, int tx, vector<int>& prices, int dp[100001][2][3]){    
        if(i== prices.size()-1){
            if(op == 0){
                return 0;
            }
            else{
                return max(0,prices.back());
            }
        }
        if(tx == 2) return 0;
        else if(dp[i][op][tx] != -1) return dp[i][op][tx];
    
        // can buy today
        if(op==0){
            //actually buys
            ll a = -prices[i] + f(i+1, 1-op, tx, prices, dp);
            //skips
            ll b =  f(i+1, op, tx, prices, dp);
            return dp[i][op][tx] = max(a,b);
        }else{
            //actually sells
            ll a = prices[i] + f(i+1, 1-op, tx+1, prices, dp);
            //skips
            ll b =  f(i+1, op, tx, prices, dp);
            return dp[i][op][tx] = max(a,b);
        }
        return INT_MIN;
    }
    int maxProfit(vector<int>& prices) {
        int dp[100001][2][3];// index, can buy/sell , transaction
        memset(dp, -1, sizeof(dp));
        ll res = f(0, 0, 0, prices, dp);
        
        return res <0 ? 0: int(res);
    }
};