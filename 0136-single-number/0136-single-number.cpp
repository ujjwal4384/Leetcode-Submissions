class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int bit =0;bit<32;bit++){
            int p = (1<<bit);
            int count = 0;
            for(auto x: nums){
                if(x & p){
                    count++;
                }
            }
            if(count%2){
                ans = ans | p;
            }
        }

        return ans;
    }
};