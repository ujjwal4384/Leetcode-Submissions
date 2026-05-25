class Solution {
    // int solve(int i, int canTake, vector<int>& nums, vector<vector<int>>&dp){
    //     if(i>= nums.size()) return 0;
    //     if(dp[i][canTake] != -1) return dp[i][canTake];
    //     int notTake = solve(i+1, 1, nums, dp);
    //     int take = INT_MIN;
    //     if(canTake){
    //         take = nums[i] + solve(i+1, 0, nums, dp);
    //     }
    //     return dp[i][canTake] = max(take, notTake);
    // }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>next(2,0), cur(2,0);
        for(int i=n-1;i>=0;i--){
            for(int canTake = 0; canTake<=1; canTake++){
                        int notTake = next[1];
                        int take = INT_MIN;
                        if(canTake){
                            take = nums[i] + next[0];
                        }
                        cur[canTake] = max(take, notTake);
            }
            next = cur;
        }
        return cur[1];
    }
};