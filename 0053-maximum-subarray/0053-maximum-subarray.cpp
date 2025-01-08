class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int n = nums.size();
         int s =0;
         int ans =INT_MIN;   
         int maxi = INT_MIN;
         for(int i=0;i<n;i++){
            maxi=max(maxi, nums[i]);
            if(s+nums[i]>=0){
                s+=nums[i];
                ans = max(ans, s);
            }else{
                s = 0;
            }
            
         }   
         return max(maxi, ans);
    }
};