class Solution {

    int helper(vector<int>& nums, int l, int r) {
        int n = nums.size();
        
        vector<int>next(2,0), cur(2,0);
        for(int i=r;i>=l;i--){
            for(int canTake = 0; canTake<=1; canTake++){
                        int notTake = next[1];
                        int take = INT_MIN;
                        if(canTake){
                            take = nums[i] + next[0];
                        }
                        cur[canTake] = max(take, notTake);
            }
            next = cur;
        }
        return cur[1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums.front();
         return max(helper(nums, 0, n-2), helper(nums, 1, n-1));
    }
};