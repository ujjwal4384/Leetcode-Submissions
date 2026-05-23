class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1), count(n,1);
        for(int i=0;i<n;i++){
            for(int j=0; j<i;j++){
                if( nums[i] > nums[j] ){
                     if(dp[i] < dp[j]+1){
                        count[i] = count[j];
                     }else if(dp[i] == dp[j]+1){
                        count[i] += count[j];
                     }
                     dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

       int max_len = *max_element(dp.begin(), dp.end());
       int freq = 0;
       for(int i=0;i<n;i++){
         if(dp[i] == max_len)freq += count[i];
       }
       return freq;
    }
};