class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n  = nums.size();
        
        int maxSum=nums[0],curSum=0;

        for(int i=0;i<n;i++){
            if(curSum+nums[i]>=0){
                curSum+=nums[i];
                maxSum= max(maxSum, curSum);
            }else{
                curSum=0;
                maxSum=max(maxSum,nums[i]);
            }
        }
        return maxSum;
    }
};