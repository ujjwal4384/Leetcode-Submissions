class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10; // Base case: length 1, we can start on any of the 10 keys
        
        long long MOD = 1e9 + 7;
        
        // dp represents the number of valid sequences ending on digit `i`
        vector<long long> dp(10, 1);
        
        for (int i = 2; i <= n; i++) {
            vector<long long> next_dp(10, 0);
            
            next_dp[0] = (dp[4] + dp[6]) % MOD;
            next_dp[1] = (dp[6] + dp[8]) % MOD;
            next_dp[2] = (dp[7] + dp[9]) % MOD;
            next_dp[3] = (dp[4] + dp[8]) % MOD;
            next_dp[4] = (dp[0] + dp[3] + dp[9]) % MOD;
            next_dp[5] = 0; // 5 has no valid outgoing or incoming moves
            next_dp[6] = (dp[0] + dp[1] + dp[7]) % MOD;
            next_dp[7] = (dp[2] + dp[6]) % MOD;
            next_dp[8] = (dp[1] + dp[3]) % MOD;
            next_dp[9] = (dp[2] + dp[4]) % MOD;
            
            dp = next_dp;
        }
        
        long long total_sequences = 0;
        for (int i = 0; i < 10; i++) {
            total_sequences = (total_sequences + dp[i]) % MOD;
        }
        
        return total_sequences;
    }
};