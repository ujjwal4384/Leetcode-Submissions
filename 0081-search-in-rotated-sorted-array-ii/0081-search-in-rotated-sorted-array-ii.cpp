class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0, r = nums.size() - 1;
        
        while(l<=r){
            int m = l + ((r-l)>>1);
            if(nums[m] == target) return true;
            
            //check which half is sorted: left/right based on that make a decision wether element lies in sorted part or not
            if (nums[l] == nums[m] && nums[m] == nums[r]) {
                l++;
                r--;
                continue; // Skip the rest, recalculate mid with tighter bounds
            }
            //left part sorted
            if(nums[l] <= nums[m]){
                 if(target >= nums[l] && target < nums[m]) r = m - 1;
                 else l = m + 1;

            }else{//right part sorted
                if(target > nums[m] && target <= nums[r]) l = m + 1;
                 else r = m - 1;
            }
        }
        return false;
    
    }
};