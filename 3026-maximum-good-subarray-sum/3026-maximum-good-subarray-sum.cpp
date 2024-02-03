class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = LLONG_MIN;
        vector<long long> psum{0};
        unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        psum.push_back(psum.back() + nums[i]); // Prefix Sum
        for(auto x:{nums[i]-k, nums[i]+k}){   
                auto it =m.find(x);
                if (it != m.end()){
                    long long cur = psum[i + 1] - psum[it->second];
                    res = max(res, cur); // n - k
                }
        }    
        auto it=m.find(nums[i]);
        if(it==m.end()){
             m[nums[i]] = i; 
             continue;
        }
        long long tempSum = psum[i] - psum[it->second] ;
        if(tempSum<=0){
             m[nums[i]] = i; 
             continue;
        }
    }
        
    return res == LLONG_MIN ? 0 : res;
    }
};
