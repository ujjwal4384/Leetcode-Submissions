class Solution {
public:
   
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size(), m = nums2.size();
        vector<vector<int>>dp(n, vector<int>(m , 0));
        //dp[i][j]= stores max same prefix length starting from nums1 ka ith and nums2 ka jth index
        //dp[i][j]= suffix strating from ith index of nums1 and jth index of nums2.

        //the length of the longest common contiguous sequence that starts precisely at index i in the first array/string and index j in the second.
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(nums1[i] == nums2[j]){
                    dp[i][j] = 1 + (i+1<n && j+1<m ?dp[i+1][j+1]: 0);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        int max_val = INT_MIN;
        for (const auto& row : dp) {
            for (int val : row) {
                if (val > max_val) max_val = val;
            }
        }
       return max_val;
    }
};