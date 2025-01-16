class Solution {
public:
    int f(int i, vector<int>& stones,int amount,  vector<vector<int>>&dp){
        //BASE CASE
        if(i==0){
            return amount >= stones[0] ? stones[0] : 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take = INT_MIN, notTake =INT_MIN;
        notTake = 0 + f(i-1, stones, amount, dp);
        if(amount-stones[i]>=0){
            take =  stones[i] + f(i-1, stones, amount-stones[i] , dp);
        }

        return dp[i][amount] = max(take, notTake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum =0;
        int n= stones.size();
        for(auto&x:stones)sum+=x;

        
        vector<vector<int>>dp(n, vector<int>(sum/2+3, -1));
        
        f(n-1, stones, sum/2, dp);
        
        dp[n-1][sum/2] = max(0, dp[n-1][sum/2]);
        return sum - 2*dp[n-1][sum/2] ;
    }
};