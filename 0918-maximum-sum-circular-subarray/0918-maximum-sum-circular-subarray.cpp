class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
    //two possible candidates:
    //when max sum is in middle of array = standard kadane max sum subaaray
    //when max sum is some prefix and some suffix of array = total sum - min sum subarray kadane
       
       int max_sum  = nums[0],  cur = nums[0];
       int n= nums.size();
       for(int i=1;i<n;i++){
            cur = max(cur + nums[i], nums[i]);
            max_sum= max(max_sum, cur);
       }

       int min_sum = nums[0];
       cur =nums[0];
       int sum = nums[0]; 
       for(int i=1;i<n;i++){
         sum += nums[i];
         cur = min(cur + nums[i], nums[i]);
         min_sum = min(min_sum, cur);
       }

       //one edge case: what if all min_sum is of whole array only
        //in that case- max sub array sum isn technically [] empty subarray
        //question states non-empty subarray. therefore exclude that.

       return sum != min_sum ? max(max_sum, sum - min_sum) : max_sum;
    }
};