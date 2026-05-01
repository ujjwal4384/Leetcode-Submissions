class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curSum = 0;
        double ans = INT_MIN;
        int n = nums.size();
        for(int i=0 ;i<n ; i++){
              curSum += nums[i];
              if(i>=k){
                curSum -= nums[i-k];
              }
              if(i>=k-1){
                ans = max(ans, curSum);
              }
        }
        return ans/k;
    }
};