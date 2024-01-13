class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi = nums[0], mini= nums[0];
        int ans = nums[0];
        for(int i=1;i<n;i++){
            int cand1 = maxi * nums[i];
            int cand2 = mini * nums[i];
            int cand3 = nums[i];
            int max_cand = max(cand1, max(cand2,cand3));
            int min_cand = min(cand1, min(cand2,cand3));
            ans = max(ans, max_cand);
            maxi= max_cand;
            mini=min_cand;
        }
       return ans; 
    }
};