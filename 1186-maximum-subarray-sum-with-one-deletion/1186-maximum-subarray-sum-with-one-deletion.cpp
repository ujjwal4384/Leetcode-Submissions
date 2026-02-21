class Solution {
public:
    int maximumSum(vector<int>& nums) {
         
        int n= nums.size();
        int ans = nums[0];
        int no_del = nums[0];
        int with_del = 0;
        for(int i=1;i<n;i++){
               with_del = max(no_del, with_del + nums[i]);//max(delete cur, cur+with_del);
               no_del = max(no_del +nums[i], nums[i]);
               ans = max({ans, with_del, no_del});
        }
        return ans;
    }
};