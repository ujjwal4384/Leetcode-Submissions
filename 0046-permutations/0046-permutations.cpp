class Solution {
public:
    void f(int pos, vector<int>&nums,vector<vector<int>>&res, map<int, bool>&mp,  vector<int>&v){
       if(pos==nums.size()){
           res.push_back(v);
           return;
       }
       
        for(int i=0;i<nums.size();i++){
            if(!mp[i]){
                v.push_back(nums[i]);
                mp[i]=1;
                f(pos+1, nums, res, mp, v);
                v.pop_back();
                mp[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       
        vector<vector<int>>res;
        vector<int>v;
        map<int, bool>mp;
        f(0, nums, res, mp, v);
       return res; 
    }
};