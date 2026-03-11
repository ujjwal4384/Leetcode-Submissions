class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans = 0;
        int i=31;
        while(i>=0 && ((1U<<i)&n) == 0)i--;

        for(;i>=0 ;i--){
             int bit = (1U<<i)& n;
             if(bit==0){
                 ans +=  (1U<<i);
             }
        }
        return ans;
    }
};