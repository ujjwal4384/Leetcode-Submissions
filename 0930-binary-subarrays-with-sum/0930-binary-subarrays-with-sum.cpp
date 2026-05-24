class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n= nums.size();
        unordered_map<int,int>freq;
        freq[0] =1;
        int pre = 0;
        int count_subarrays  =0;
        for(int i=0;i<n;i++){
                pre += nums[i];
                int target = pre - goal;
                if(freq.find(target) != freq.end()){
                    count_subarrays += freq[target];
                }
                freq[pre]++;
        }
        return count_subarrays;
    }
};