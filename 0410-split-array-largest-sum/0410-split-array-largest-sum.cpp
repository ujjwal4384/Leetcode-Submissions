class Solution {
    bool isValid(int m, vector<int>& nums, int k){
        int partitions = 0;
        int curSum = 0;
        for(int i=0;i<nums.size(); i++){
                if(nums[i] > m) return false;
                else if(curSum + nums[i] > m){
                     partitions++;
                     curSum = nums[i];
                }
                else{
                    curSum += nums[i];
                }
        }
        return partitions <= k-1;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        int sum = 0;
        for(auto x: nums) sum += x;
        int l = 0, r = sum;
        int ans = 0;
        while(l<=r){
            int m = l +((r-l)>>1);
            
            if(isValid(m, nums, k)) {
                ans = m; r = m-1;
            }else{
                l = m+1;
            }
        }
      return ans;
    }
};