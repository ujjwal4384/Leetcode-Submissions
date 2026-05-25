class Solution {
    int f(int i, vector<int>& nums, int target, int cur){
        if(i>=nums.size()) return cur==target;
        
        return f(i+1, nums, target, cur+nums[i]) + f(i+1, nums, target, cur-nums[i]);
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int cur = 0;
        return f(0, nums, target, cur);
    }
};