class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(auto num: nums)freq[num]++;

        int ans = 0;
        for(auto p: freq){
            if(k>0){
                if(freq.count(p.first - k))ans++;
            }else if(k==0){
                if(p.second>1)ans++;
            }
        }
        return ans;
    }
};