class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
              if(mp[target-nums[i]]){
                   return vector<int>{mp[target-nums[i]]-1, i};
              }else{
                  mp[nums[i]]=i+1;
              }
        }
        return vector<int>{-1,-1};
    }
};