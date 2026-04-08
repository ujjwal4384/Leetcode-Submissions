class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(auto&x:nums){
            if(x<=0) x = n+1;
        }
        for(int i=0;i<n;i++){
             int x = abs(nums[i]);
             if(x <=n){
                 nums[x-1] = -1 * abs(nums[x-1]) ;
             }
        }

        for(int i=0;i<n;i++)if(nums[i] > 0) return i+1;
        return n+1;
    }
};