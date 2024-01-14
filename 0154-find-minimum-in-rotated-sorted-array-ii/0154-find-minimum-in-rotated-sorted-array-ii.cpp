class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0],low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[low]==nums[mid] && nums[mid] == nums[high]){
                ans=min(ans,nums[low]);
                low++,high--;
            }
            //left half sorted=> pick minimum of left half and go to right half
            else if(nums[low]<=nums[mid]){
                ans=min(ans, nums[low]);
                low=mid+1;
            }
            //right half sorted=>pick minimum from right half and go to left half
            else{
                ans=min(ans, nums[mid]);
                high=mid-1;
            }
        }
       return ans;    
    }
};