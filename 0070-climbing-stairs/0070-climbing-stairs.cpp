class Solution {
public:
    int climbStairs(int n) {
        //fibonacci series. log(n)=> matrix exponentiaiton se.
       int last_second_step=1,last_step=1;
        if(n==1) return 1;
        int cur=0;
        
        for(int i=2;i<=n;i++){
            cur = last_step + last_second_step;
            last_second_step = last_step;
            last_step = cur;
        }
        return cur;
    }
};