class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = LLONG_MIN;
         int n=nums.size();
        vector<long long>pre(n,0);
        for(int i=0;i<n;i++){
            if(i==0)pre[i]=nums[i];
            else pre[i]=pre[i-1]+nums[i];
        }
       
        unordered_map<long long, long long> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (auto it = m.find(nums[i] - k); it != end(m)){
            res = max(res, pre[i] - (it->second==0?0:pre[it->second-1]) ); // n - k
        }
        if (auto it = m.find(nums[i] + k); it != end(m)){
             res = max(res, pre[i] - (it->second==0?0:pre[it->second-1]) ); // n + k
        }
        auto it =m.find(nums[i]);
        if(it==m.end()){
             m[nums[i]] = i;
            continue;
        }
        long long int tempSum =(i==0?0:pre[i-1]) - (it->second==0?0LL:pre[it->second-1]);
        if (tempSum<=0){
            m[nums[i]] = i; // Kadane
        }
    }
    return res == LLONG_MIN ? 0 : res;
    }
};
