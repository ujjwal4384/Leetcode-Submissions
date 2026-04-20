class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>bucket(n+1);
        vector<int>freq(20005);

        for(auto n:nums){
             freq[n+10000]++;
        }

        for(int i=0;i<freq.size(); i++){
                if(freq[i] > 0){
                    bucket[freq[i]].push_back(i-10000);
                }
        }
        vector<int>ans;
        for(int i=bucket.size()-1 ; i>=0 ;i--){
            for(auto x: bucket[i]){
                if(ans.size() == k)break;
                ans.push_back(x);
            }
            if(ans.size()==k)break;
        }
        return ans;
    }
};