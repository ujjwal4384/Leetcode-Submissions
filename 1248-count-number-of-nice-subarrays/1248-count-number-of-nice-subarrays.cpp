class Solution {
    int countAtMost(vector<int>& nums, int k){
          if(k<0) return 0;
          int count_odd = 0;
          int ans = 0;
          int l =0;
          for(int r=0;r<nums.size(); r++){
               if(nums[r]%2)count_odd++;
               while(count_odd >k){
                   if(nums[l]%2)count_odd--;
                   l++;
               }
               ans += (r-l+1);
          }
       return ans;  
   }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k-1);
    }
};