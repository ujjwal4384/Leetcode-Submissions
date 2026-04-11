class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1 = -1, ans2 = -1;
        int l = 0, r = nums.size() -1;
        while(l<=r){
             int m = l + ((r-l)>>1) ;
             
             if(nums[m] >= target){
                if(nums[m] == target)ans1 = m;
                r = m-1;
             }
             else {
                l = m+1;
             }
        }

        l = 0, r = nums.size() -1;
        while(l<=r){
             int m = l + ((r-l)>>1) ;
             
             if(nums[m] <= target){
                if(nums[m] == target)ans2 = m;
                l = m + 1;
             }
             else {
                r = m -1;
             }
        }

        return {ans1, ans2};
    }
};