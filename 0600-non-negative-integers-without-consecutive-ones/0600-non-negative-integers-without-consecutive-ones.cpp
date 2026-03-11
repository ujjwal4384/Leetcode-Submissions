class Solution {
public:
    int findIntegers(int n) {
        int fib[33] ={0};
        //fib [i] = no. of ways for string of length i.
        fib[0] = 1;
        fib[1] = 2;
        for(int i=2;i<33;i++)fib[i] = fib[i-1] + fib[i-2];

        int ans =0;
        int prev_bit = 0;
        for(int i=31;i>=0;i--){
            int bit = n & (1<<i);
            if(bit == 0){
                prev_bit = 0;
            }else{
                //if we put 0 in this pos, then all ways of length i
                ans += fib[i];

                //now we put 1. 
                if(prev_bit ==1) return ans; //illegal formation 11 subsequent all numbres will be also illegal
                prev_bit =1;
            }
        }
        //if N doesnot itself ahs 11 then us case mei, N is also valid answer so add 1
        return ans +1;

    }
};