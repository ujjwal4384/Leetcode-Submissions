class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, vector<int>> lookup;
        vector<long long int> prefix(n, 0);
        
        for (int i = 0; i < n; i++){
            lookup[nums[i]].push_back(i);
            prefix[i] = nums[i];
            if (i > 0){
                prefix[i] += prefix[i-1];
            }
        }

        
        bool found = false;
        long long int ans{0};
        
        for (int i = 0; i < n; i++){
            for (int a : {nums[i] - k, nums[i] + k}){
                for (int j : lookup[a]){
                    if (j > i){
                        long long int s;
                        if (i > 0)
                           s = prefix[j] - prefix[i-1];
                        else 
                            s = prefix[j];
                        if (!found){
                            ans = s;
                            found = true;
                        } else {
                            ans = std::max(ans, s);
                        }
                    }
                }                
            }
        }
        
        return ans;
        
    }
};