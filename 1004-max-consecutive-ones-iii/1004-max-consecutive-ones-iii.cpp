class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int n = nums.size();
         int l=0; int max_streak = k;
         int debt = 0;
         for(int r=0;r<n;r++){
                if(nums[r] == 0)debt++;
                while(debt>k){
                    if(nums[l] == 0)debt--; //refund
                    l++;
                }
                max_streak = max(max_streak, r-l+1);
         }

         return max_streak;
    }
};