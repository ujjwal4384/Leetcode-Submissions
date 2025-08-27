class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int n= nums.size();
        
        for(auto&x:nums)sum+=x;
        if(sum < target) return 0;

        int ans =n, cur=0;
        for(int l=0,r=0;r<n;r++){
            int val = nums[r];
            cur += val;
            if(cur< target){
                continue;
            }
            
            while(l<=r && cur>=target){
                cur -= nums[l];
                ans = min(ans, r-l+1);
                l++;
            }
            
        }

        return ans;
    }
};