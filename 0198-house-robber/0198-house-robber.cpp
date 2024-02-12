class Solution {
public:
    int f(int i, vector<int>&nums, int canTake, int dp[500][2]){
        if(i>=nums.size())return 0;
        if(dp[i][canTake]!=-1) return dp[i][canTake];
        int f1=INT_MIN,  f2=INT_MIN;
        if(canTake){
            //takes it
             f1 = nums[i]+ f(i+1, nums, 0, dp);
           
            //doesn't take
             f2 = f(i+1, nums, 1, dp);
        }else{
            //cannot take it. 
            f2 = f(i+1, nums, 1, dp);
        }
       return dp[i][canTake] =  max(f1, f2); 
    }
    int rob(vector<int>& nums) {
        int maxi=INT_MIN;
        int dp[500][2];
        memset(dp, -1, sizeof(dp));
        
      return f(0, nums, 1, dp);      
    }
};