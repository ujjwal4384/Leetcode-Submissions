class Solution {
public:
    int climbStairs(int n) {
          if(n<=1) return n;
          int lastSecondStepWays = 1, lastStepWays = 1;
          for(int step = 2; step<=n;step++){
                int cur = lastSecondStepWays + lastStepWays;
                lastSecondStepWays = lastStepWays;
                lastStepWays = cur;
          }
         return lastStepWays; 
    }
};