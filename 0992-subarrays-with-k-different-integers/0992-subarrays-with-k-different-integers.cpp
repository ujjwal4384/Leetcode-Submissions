class Solution {
public:
    int atmostKDistinct(vector<int>& nums, int k){
       int n = nums.size();
       int l=0, r=0;
       int count = 0;
       unordered_map<int,int>freqMap;
       while(r<n){
             int x = nums[r];
             freqMap[x]++;
             while(freqMap.size() > k){
                  freqMap[nums[l]]--;
                  if(freqMap[nums[l]] == 0)freqMap.erase(nums[l]);
                  l++;
             }
             count += (r-l+1);
             r++;
       }
       return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostKDistinct(nums, k) - atmostKDistinct(nums, k-1);
    }
};