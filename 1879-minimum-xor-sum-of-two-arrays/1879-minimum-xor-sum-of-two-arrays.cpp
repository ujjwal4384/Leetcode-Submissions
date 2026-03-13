class Solution {
    int dp[20000];//dp[i][mask]. i= cur position in nums1. mask= what elemtns have been already picked and what are remainig to be piocked in nums2. stores minium xor we can obtain starting from index 0 of nums1 where mask state of elements in nums2 are remainign to be picked.
public:
    int solve(int mask, vector<int>& nums1, vector<int>& nums2){
        int i = __builtin_popcount(mask) ;//count of 1s in mask => how many nums2 have been paired => which index of nums1 w want tomc urrently look for is i. //O(1)
        if(i==nums1.size()){
            return 0;
        }
        else if(dp[mask] !=-1) return dp[mask];
        int ans = INT_MAX;    
        for(int j=0;j<nums2.size(); j++){
              bool canPickThisElement = (mask & (1<<j)) ==0;
              if(canPickThisElement){
                   int cur = (nums1[i] ^ nums2[j])  + solve(mask | (1<<j), nums1, nums2);
                   ans = min(ans, cur); 
              }   
        }
        return dp[mask] = ans;
    } 

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return solve( 0, nums1, nums2) ;
    }
};