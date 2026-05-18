class Solution {
public:
    void solve(int i, vector<int>& nums, vector<vector<int>>&res, vector<int>& cur){
        if(i>= nums.size()){
            res.push_back(cur);
            return;
        }
        solve(i+1, nums, res, cur);
        cur.push_back(nums[i]);
        solve(i+1, nums, res, cur);
        cur.pop_back();
        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>cur;
        solve(0, nums, res, cur);
        return res;
    }
};