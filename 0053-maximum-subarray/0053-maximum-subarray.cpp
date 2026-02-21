class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int ans = nums[0];
        int curSum = nums[0];
        for(int i=1;i<n;i++){
               curSum = max(nums[i], curSum + nums[i]);
               ans = max(ans, curSum) ;
        }
        return ans;
    }
};