class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int l =0, r= n - 1;
        int ans = nums[0];
        while(l<=r){
            int m = l + ((r-l)>>1);
            //if left half sorted: pick min of lefft half and move to right
            if(nums[m] >= nums[l] ){
                ans = min(ans, nums[l]);
                l= m+1;
            }else{
                ans = min(ans, nums[r]);
                r= m-1;
            } 
        }
        return ans;
    }
};