class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n, 1), dp2(n, 1);
        for(int i=0;i<n;i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i])
                    dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=n-1; j>=i+1; j--){
                if(nums[j] < nums[i])
                    dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }

        int mini = n;
        for(int i=1;i<n-1;i++){
            //if nums[i] is mountain array then
            int leftRemovalCount =  i - (dp1[i]-1);      //total i elements to left of nums[i] and (dp1[i]-1) are strictly increasing, remainig need to be removed.
            int rightRemovalCount =  (n-1-i) - (dp2[i]-1);
            if(leftRemovalCount == i  ||  rightRemovalCount == (n-1-i)){
                //if all have to be removed then nums[i] cannot be mountain
                continue;
            }
            mini = min(mini, leftRemovalCount + rightRemovalCount);
        }
        return mini;
    }
};