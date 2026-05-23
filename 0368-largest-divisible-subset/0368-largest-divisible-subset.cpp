class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int global_max = 0;
        int last_id = -1;
        vector<int>par(n, -1);
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j] + 1){
                     dp[i] = dp[j] + 1;
                     par[i] = j;
                }
            }
            if(dp[i] > global_max){
                last_id = i;
                global_max = dp[i];
            }
        }

        vector<int>ans;
        int cur = last_id;
        while(cur != -1){
              ans.push_back(nums[cur]);
              cur = par[cur];
        }
        return ans;
    }
};