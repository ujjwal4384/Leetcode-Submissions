class Solution {
    int dp[14][20000];//dp[i][mask]. i= cur position in nums1. mask= what elemtns have been already picked and what are remainig to be piocked in nums2. stores minium xor we can obtain starting from index 0 of nums1 where mask state of elements in nums2 are remainign to be picked.
public:
    int solve(int i, int mask, vector<int>& nums1, vector<int>& nums2){
        if(i==nums1.size()){
            return 0;
        }
        else if(dp[i][mask] !=-1) return dp[i][mask];
        int ans = INT_MAX;    
        for(int j=0;j<nums2.size(); j++){
              bool canPickThisElement = (mask & (1<<j)) ==0;
              if(canPickThisElement){
                   int cur = (nums1[i] ^ nums2[j])  + solve(i+1, mask | (1<<j), nums1, nums2);
                   ans = min(ans, cur); 
              }   
        }
        return dp[i][mask] = ans;
    } 

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums1, nums2) ;
    }
};