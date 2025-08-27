class Solution {
public:
    int f(int i, int canPick, vector<int>& nums, int dp[101][2]){
        if(i>=nums.size()) return 0;
        else if(dp[i][canPick] !=-1) return dp[i][canPick];


        if(canPick){
            // actually picks, toggle nes=xt indexes state
            int a = nums[i] + f(i+2, canPick, nums, dp);
            // skips
            int b = f(i+1, canPick, nums, dp);
            return dp[i][canPick] = max(a, b);
        }else{
            // can't pick, toggle next indexes state of pick.
             return dp[i][canPick] =f(i+1, !canPick, nums, dp);   
        }
        return 0;
    }
    int rob(vector<int>& nums) {
        int dp[103][2];
        memset(dp, 0, sizeof(dp));

        for(int i=nums.size()-1;i>=0;i--){
            for(int canTake = 0;canTake<=1;canTake++){
                if(canTake){
                    int a = nums[i] + dp[i+2][canTake];
                    int b = dp[i+1][canTake];
                    dp[i][canTake] = max(a, b);
                }else{
                    dp[i][canTake] = dp[i+1][!canTake];   
                }
                
            }
        }

        return dp[0][1];
    }
};