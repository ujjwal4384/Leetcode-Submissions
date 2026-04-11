class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //we need boundary: first matching for nums[i] >= target.
        int ans = nums.size();
        int l = 0, r = nums.size() -1;
        while(l<=r){
             int m = l + ((r-l)>>1) ;
             if(nums[m] == target){
                return m;
             }
             else if(nums[m] < target){
                l = m+1;
             }
             else {
                ans = m;
                r = m-1;
             }
        }
        return ans;
    }
};