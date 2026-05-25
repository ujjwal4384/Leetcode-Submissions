class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
                 int n = nums.size();        
        int total_sum = 0;
        for(auto& x: nums) total_sum += x;

        
        
        if(total_sum%2) return 0;
        int target = total_sum / 2;    

        
       vector<bool>prev(target+1),cur(target+1);
       prev[0] = 1;
        for(int i=1; i<=n; i++){
            for(int sum=0;sum<=target; sum++){
                   bool take = 0, notTake = 0;
                   notTake = prev[sum];
                   if(sum-nums[i-1]>=0){
                    take = prev[sum-nums[i-1]];
                   }

                    cur[sum] = take || notTake;
            }
            prev = cur;
        }
        return prev[target];
    }
    
};