class Solution {
    int solve(int i, int canTake, vector<int>& nums, vector<vector<int>>&dp){
        if(i>= nums.size()) return 0;
        if(dp[i][canTake] != -1) return dp[i][canTake];
        int notTake = solve(i+1, 1, nums, dp);
        int take = INT_MIN;
        if(canTake){
            take = nums[i] + solve(i+1, 0, nums, dp);
        }
        return dp[i][canTake] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return solve(0, 1, nums, dp);
    }
};