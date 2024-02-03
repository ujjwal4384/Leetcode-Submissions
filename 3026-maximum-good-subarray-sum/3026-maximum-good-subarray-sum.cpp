class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> lookup;
        vector<long long int> prefix(n, 0);
        
        for (int i = 0; i < n; i++){
           
            prefix[i] = nums[i];
            if (i > 0){
                prefix[i] += prefix[i-1];
            }
        }

        
        bool found = false;
        long long int ans{0};
        long long cur=0;
        for (int i = 0; i < n; i++){
            cur+=nums[i];
            for (int a : {nums[i] - k, nums[i] + k}){
                for (int j : lookup[a]){
                    
                        long long int s;
                       
                        s = cur - (j-1>=0?prefix[j-1]:0LL);
                        
                    if (!found){
                            ans = s;
                            found = true;
                        } else {
                            ans = std::max(ans, s);
                        }
                    
                }                
            }
             lookup[nums[i]].push_back(i);
        }
        
        return ans;
        
    }
};