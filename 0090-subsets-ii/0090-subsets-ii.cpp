class Solution {
public:
    void f(vector<int>&nums, int pos,vector<vector<int>>&res,vector<int>&v){
        if(pos>=nums.size()){
            res.push_back(v);
            return;
        }
        v.push_back(nums[pos]);
        f(nums, pos+1, res, v);
        v.pop_back();
       
        int j=pos+1;
        while(j<nums.size() && nums[j]==nums[j-1])j++;
        f(nums, j, res, v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>res;
        vector<int>v;
        f(nums, 0, res, v);      
        return res;
    }
};