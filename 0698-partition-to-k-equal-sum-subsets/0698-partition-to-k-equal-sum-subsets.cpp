class Solution {
    int target_sum;
    int target_mask ;
    vector<int>v;
    int dp[1<<16];
public:
    bool solve(int mask, int cur_bucket_sum){
        if(mask == target_mask){
            return true;
        }
        if(dp[mask] != -1) return dp[mask];

        for(int i=0;i<v.size(); i++){
            bool canPick = (mask & (1<<i) )  == 0;
            if(canPick){
                if(cur_bucket_sum + v[i] == target_sum){
                             bool f = solve(mask | (1<<i), 0);
                             if(f) return true;
                }
                else if(cur_bucket_sum + v[i] < target_sum){
                             bool f = solve(mask | (1<<i), cur_bucket_sum + v[i]);
                             if(f) return true;
                }
            }
        }
        return dp[mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        v= nums;
        target_mask = (1 << nums.size()) -1 ;
        memset(dp, -1, sizeof(dp));
        
        int s =0;
        for(auto x:nums) s += x;
        if(s%k != 0) return false;
        target_sum = s/k;
     
        return solve(0, 0);
    }
};