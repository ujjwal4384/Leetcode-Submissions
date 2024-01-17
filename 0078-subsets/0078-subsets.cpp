class Solution {
public:
    void f(vector<int>&nums, int pos, vector<vector<int>>&res, vector<int>&v ){
        if(pos==nums.size()){
            res.push_back(v);
            return;
        }
        v.push_back(nums[pos]);
        f(nums, pos+1, res, v);
        v.pop_back();
        f(nums, pos+1, res, v);
       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        f(nums, 0, res, v);
        return res;
            
    }
};