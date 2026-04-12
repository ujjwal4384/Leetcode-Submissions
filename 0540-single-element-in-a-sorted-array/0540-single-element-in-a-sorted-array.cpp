class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int a =0;
      for(auto x:nums) a ^= x;
      return a;   
    }
};