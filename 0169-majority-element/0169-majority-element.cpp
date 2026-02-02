class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majIndex = 0;
        int c =0;
        for(int i=0 ; i<n; i++){
            if(c == 0){
                majIndex = i;
            }
            if(nums[i] == nums[majIndex]){
                c++;
            }else{
                c--;
            }
        }

        int freqMajEl = 0;
        for(auto & x: nums){
            if(x == nums[majIndex]) freqMajEl++;
        }

        return freqMajEl > n/2 ? nums[majIndex] : -1;
    }
};