class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        int xorr = 0;
        for(auto x: nums)xorr ^= x;

        //xorr = a^b. of two numbers.
        //find any bit which is set => that bit is diff in both nums

        int difBit = 0;
        for(int bit =0;bit<32 ;bit++){
            int p = (1<<bit);
            if(xorr & p){
                difBit = bit;
                break;
            }
        }

        int xorr1=0,xorr2=0;  //make 2 buckets

        int p = (1<<difBit);

        for(auto y:nums){
               if(y & p){
                xorr1 ^= y;
               }  else{
                xorr2 ^= y;
               }   
        }
      return {xorr1, xorr2};  
    }
};