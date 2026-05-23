class Solution {

    vector<int> getLISLengths(const vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> tails;
        
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
            if (it == tails.end()) {
                tails.push_back(nums[i]);
                dp[i] = tails.size(); // The length is the new size of the tails array
            } else {
                *it = nums[i];
                dp[i] = distance(tails.begin(), it) + 1; // The length is its position + 1
            }
        }
        return dp;
    }

public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n, 1), dp2(n, 1);
        dp1 = getLISLengths(nums);
        reverse(nums.begin(), nums.end());
        dp2 = getLISLengths(nums);
        reverse(dp2.begin(), dp2.end()) ;
        
        int mini = n;
        for(int i=1;i<n-1;i++){
            //if nums[i] is mountain array then
            int leftRemovalCount =  i - (dp1[i]-1);      //total i elements to left of nums[i] and (dp1[i]-1) are strictly increasing, remainig need to be removed.
            int rightRemovalCount =  (n-1-i) - (dp2[i]-1);
            if(leftRemovalCount == i  ||  rightRemovalCount == (n-1-i)){
                //if all have to be removed then nums[i] cannot be mountain
                continue;
            }
            mini = min(mini, leftRemovalCount + rightRemovalCount);
        }
        return mini;
    }
};