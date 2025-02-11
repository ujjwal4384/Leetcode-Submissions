class Solution {
public:
    void f(int i, vector<int>& nums, vector<int>&v,vector<vector<int>>&vv){
        if(i==nums.size()){
            vv.push_back(v);
            return;
        }

        //take
        v.push_back(nums[i]);
        f(i+1, nums, v, vv);
        v.pop_back();
        
        //noTake

        //then not take any other same element as well
        int j = i+1;
        while(j<nums.size() && nums[j]==nums[i])j++;

        f(j, nums, v, vv);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>vv;
        vector<int>v;
        
        f(0, nums, v, vv);

        return vv;
    }
};