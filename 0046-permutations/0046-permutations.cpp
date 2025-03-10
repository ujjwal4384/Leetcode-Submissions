class Solution {
public:
    void f(int i, vector<int>& nums, vector<vector<int>>&res){
        if(i== nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int k=i;k<nums.size(); k++){
            swap(nums[i], nums[k]);
            f(i+1, nums, res);
            swap(nums[i], nums[k]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        f(0, nums, res);
        return res;
    }
};