class Solution {
public:
    int f(int i, int take, vector<int>& nums, int dp[101][2], int closing){
        if(i>=closing){
            return 0;
        }
        
       if(dp[i][take] !=-1) return dp[i][take];

        if(take){
            return dp[i][take] = nums[i] +  f(i+1, 0, nums, dp, closing) ;
        }
        else{ 
            return dp[i][take] = max(f(i+1, 1, nums, dp, closing), f(i+1, 0, nums, dp, closing));
        }

        return -1;
    } 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int dp[101][2];
        memset(dp, -1, sizeof(dp));
        
        int pickedHouse1 = f(0, 1, nums, dp, n-1);
        memset(dp, -1, sizeof(dp));
        int notPickedHouse1 = f(0, 0, nums, dp, n);
        
        return max (pickedHouse1, notPickedHouse1); 
    }
};