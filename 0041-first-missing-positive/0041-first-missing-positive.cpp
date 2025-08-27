class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n= nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(x<=0) nums[i] = n+1;
        }

        for(int i=0;i<n;i++){
            int x = nums[i];
            if(abs(x)<=n){
                nums[abs(x) -1] = -1 * abs(nums[abs(x) -1]); 
            }
        }


        for(int i=0;i<n;i++){
            int x = nums[i];
            if(x >0) return i+1;
        }
     return n+1;
        
    }
};