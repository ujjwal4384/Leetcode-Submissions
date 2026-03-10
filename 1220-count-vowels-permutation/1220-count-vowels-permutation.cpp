class Solution {
    int MOD = 1e9+7;
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>>dp(n, vector<long long>(5, 0));
        //dp[i][j] = valid ways till ith index which ends at vowel j.
        for(int j=0;j<5;j++){
            dp[n-1][j] = 1;
        }
        //a->0, e->1, i->2, o->3, u->4
        for(int i=n-2;i>=0;i--){
            dp[i][0] =  dp[i+1][1];
            dp[i][1] =  (dp[i+1][0] + dp[i+1][2] + MOD)%MOD;
            dp[i][2] =  (dp[i+1][0] + dp[i+1][1] + dp[i+1][3] + dp[i+1][4] + MOD)%MOD;
            dp[i][3] =  (dp[i+1][2] + dp[i+1][4]+MOD)%MOD;
            dp[i][4] =  (dp[i+1][0] + MOD)%MOD ;
        }
        int ans = 0;
        for(int j=0;j<5;j++){
            ans = (ans + dp[0][j] + MOD)%MOD;
        }
        return ans;
    }
};