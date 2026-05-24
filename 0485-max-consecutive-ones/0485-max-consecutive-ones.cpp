class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi =0, cur = 0;
        int r=0;
        while(r<n){
            if(nums[r]==0){
                cur = 0;
                r++;
                continue;
            }
            while(r<n && nums[r]==1){
                cur++;
                r++;
            }
            maxi = max(maxi, cur);
        }
        return maxi;
    }
};