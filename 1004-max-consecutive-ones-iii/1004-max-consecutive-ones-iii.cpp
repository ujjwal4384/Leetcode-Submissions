class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0;
        int maxi = 0;
        int balance = k;
        while(r<n){
                if(nums[r] == 0)balance--;
                while(balance <0 && l<=r){
                    if(nums[l]==0)balance++;
                    l++;
                }
                maxi = max(maxi, r-l+1);
                r++;
        }
        return maxi;
    }
};