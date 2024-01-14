class Solution {
public:
    int findMin(vector<int>& nums) {
     //let ans= nums[0]; find sorted half pick minimum of sorted half and go to other half
        int n=nums.size();
        int ans=nums[0],low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)>>1;
            //left half sorted=> pick minimum of left half and go to right half
            if(nums[low]<=nums[mid]){
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