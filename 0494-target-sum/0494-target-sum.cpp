class Solution {
    int f(int i, vector<int>& nums, int target, int dp[21][2001]){
        if(target<0 || i>nums.size()) return 0;
        if(i==nums.size())return target==0;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        return  dp[i][target] = f(i+1, nums, target - nums[i], dp) + f(i+1, nums, target, dp);      
    }



public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //look all numbers are positive. 
        //original problem -> wayas to build target. it can be negative also. so inorder to aovid using map for dp.
        //reframe problem- P =numbers having positive sign, N = numbers with negative sign/ 
        //P-N = target, also P + N = total_sum. Hence add 2 equation-> p = (target + sum)/2. this will always be >=0 
        //Becasue if target < sum => not possible only becasue max we can get is [-sum, +sum].
        //hence now we just weant subsets with total = k= (target+sum)/2 ;

        
        int total_sum = 0;
        for(auto& x: nums) total_sum += x;
        if(abs(target) > total_sum) return 0;
        int dp[21][2001];
        memset(dp, -1, sizeof(dp));
        int p = (target + total_sum);
        if(p%2) return 0;
        p /= 2;    
        return f(0, nums, p, dp);
    }
};