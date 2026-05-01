class Solution {
    int solve(int i, int last_jump, vector<int>& stones, vector<vector<int>>&dp){
         if(i>=stones.size()-1) return true;
         else if(dp[i][last_jump] != -1) return dp[i][last_jump];
         for(int delta=-1;delta<=1;delta++){
            int new_jump = last_jump + delta;
            if(new_jump <=0) continue;
            int new_pos = stones[i] + new_jump;
            int j = lower_bound(stones.begin() + i+1,stones.end(), new_pos) - stones.begin();
            if(j >= stones.size() || stones[j] != new_pos) continue;  
            if(solve(j, new_jump, stones, dp)) return dp[i][last_jump] = true;  
         }
         return dp[i][last_jump] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n <=1) return true;
        if(stones[1] - stones[0] != 1) return false;
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return (solve(1,1,stones, dp) == 1);
    }
}; 