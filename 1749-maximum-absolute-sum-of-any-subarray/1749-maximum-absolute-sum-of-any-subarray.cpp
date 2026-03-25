class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>>dp(n, {INT_MIN, INT_MAX});
        dp[0] = {nums[0], nums[0]};
    
        for(int i=1;i<n; i++){
            int maxi = max({dp[i-1].first + nums[i], dp[i-1].second+nums[i], nums[i]});
            int mini = min({dp[i-1].first + nums[i], dp[i-1].second + nums[i], nums[i]});
            dp[i] = {maxi, mini};
        }
        int ans = INT_MIN;
        for(auto p: dp)ans= max({ans, abs(p.first), abs(p.second)});

        return ans;
    }
};