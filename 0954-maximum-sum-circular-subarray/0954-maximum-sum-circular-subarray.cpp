class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        // CASE 1: MAX SUM is in MIDDLE
        int maxSum = nums[0], curSum = nums[0];
        int tot = nums[0];
        int maxi = nums[0];
        for (int i = 1; i < n; i++) {
            tot += nums[i];
            maxi = max(maxi, nums[i]);

            curSum = max(nums[i], curSum + nums[i]);
            maxSum = max(maxSum, curSum);
        }

        // CASE 2: MAX SUM is some part of prefix and some part of suffix.
        // so = total sum - min sum by kadane algorithm.

        int minSum = nums[0];
        curSum = nums[0];

        for (int i = 1; i < n; i++) {
            curSum = min(nums[i], curSum + nums[i]);
            minSum = min(minSum, curSum);
        }

        if(minSum == tot)return maxSum;
        return max(maxSum, tot - minSum);
    }
};