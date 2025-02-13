class Solution {
public:
    int singleNumber(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;      

            for(int bit = 0; bit<32; bit ++){
                int p = (1<<bit);
                int totalBitSet = 0;
                for(auto x:nums){
                       if(x & p){
                           totalBitSet ++; 
                       } 
                }

                if(totalBitSet % 3 ==1){
                    ans += p;
                }
            }

           return ans; 
    }
};