class Solution {
    bool isSubsetSum(int i, vector<int>&v, int target){
        if(target == 0) return true;
        else if(i>=v.size()) return false;
        
        bool notTake = isSubsetSum(i+1, v, target);
        bool take = false;
        if(target-v[i]>=0)take = isSubsetSum(i+1, v, target-v[i]);

        return notTake || take ;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
// N independent subset-sum problem. for every index find wether nums[i] target can be achieved by array so far.
        int n=nums.size();

        bool allZero = true;
        for(int x : nums){
            if(x != 0){
                allZero = false;
                break;
            }
        }
        if(allZero) return 0;
        vector<vector<int>>available_values(n);
        vector<vector<bool>>dp(n);
        for(int i=0;i<n;i++){
             dp[i].assign(nums[i]+1, false);
             dp[i][0] = true;
        }
        for(int q=0;q<queries.size(); q++){
                int l = queries[q][0], r = queries[q][1], val = queries[q][2];
                
                for(int k=l;k<=r;k++){
                   if (val > nums[k]) continue; 
                   for(int sum = nums[k]; sum>=val; sum--){
                       if(dp[k][sum-val])dp[k][sum] = true; 
                   }
                }
                bool valid = true;
                for(int i=0;i<n;i++){
                    if(dp[i][nums[i]]==false){
                        valid = false;
                        break;
                    }
                }
                if(valid) return q+1; 
        }

        return -1;
    }
};
