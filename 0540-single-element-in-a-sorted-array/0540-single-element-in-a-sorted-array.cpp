class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        int l=0,r=n-1;
        
        while(l<=r){
            int m = (l+r)/2;
            //cout<< m<<" \n";
            if(m==0){
                if(nums[m+1] != nums[m])return nums[m];
                l= m+1;
            }else if(m==n-1){
                if(nums[m-1] != nums[m])return nums[m];
                r= m - 1;
            }else{
                if(nums[m+1] != nums[m] && nums[m-1] != nums[m])return nums[m];

                else if(nums[m] == nums[m-1]){
                   if(m%2){
                        l = m+1;
                   } 
                   else{
                         r = m-1;
                    }
                }
                else if(nums[m] == nums[m+1]){
                    if(m%2){
                        r = m-1;
                   } 
                   else{
                        l = m+1;
                    }
                }
            }
        }

        return -1;
    }
};