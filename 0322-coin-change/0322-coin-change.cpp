class Solution {
public:
    int f(int i, vector<int>& coins, int amount, vector<vector<int>>&dp){
        //BASE CASE
        if(i==0){
            //...
            if(amount ==0){
                return 0;
            }
            return amount>=coins[0] && amount%coins[0]==0 ? amount/coins[0] : 1e5;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=1e5, notTake=1e5;
        notTake = 0 + f(i-1, coins, amount, dp);
        if(amount-coins[i]>=0){
            take = 1 + f(i, coins, amount-coins[i], dp);
        }

        return dp[i][amount] =min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        //solve like kanpsack. 
        //0-1 kanpsack em we had ot maximize the value, here minimuize the number of coins. here we have infinite supply.
        int n= coins.size();
        // vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        // int ans = f(n-1, coins, amount, dp);
    
        // vector<vector<int>>dp(n, vector<int>(amount+1, 0));    
        vector<int>prev(amount+1,0),cur(amount+1,0);
        for(int am=1;am<=amount;am++){
            prev[am] = am>=coins[0] && am%coins[0]==0 ? am/coins[0] : 1e5;
        }

        for(int i=1;i<n;i++){
            for(int am =0 ; am<=amount; am++){
                  
                int take=1e5, notTake=1e5;
                notTake = 0 + prev[am];
                if(am-coins[i]>=0){
                    take = 1 + cur[am-coins[i]];
                }

                cur[am] =min(take, notTake);
            }
            prev = cur;
        }
        int ans = prev[amount];
        return ans ==1e5?-1:ans;
    }
};