class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int minPre =0, maxPre = 0;
        int sum = 0;
        for(int i=0;i<n; i++){
            sum += nums[i];
            minPre = min(minPre, sum);
            maxPre = max(maxPre, sum);
        }
        return maxPre- minPre;
    }
};