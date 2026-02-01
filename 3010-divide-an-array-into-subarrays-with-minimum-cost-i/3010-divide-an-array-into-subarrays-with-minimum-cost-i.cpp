class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int minElement = INT_MAX;
        int secondMinElement = INT_MAX;
        for(int i=1;i<n;i++){
             int x = nums[i];
             if(nums[i] < minElement){
                secondMinElement = minElement;
                minElement = nums[i];
             }else if(nums[i] <secondMinElement){
                secondMinElement = nums[i];
             }
        }
       return nums[0] + minElement + secondMinElement; 
    }
};