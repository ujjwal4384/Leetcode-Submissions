class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n<=0) return 0;
        
        
        int lastStepMin = 0, secondLastStepMin = 0;
        for(int i=2;i<=n;i++){
            int newlastStepMin = min(secondLastStepMin + cost[i-2], lastStepMin + cost[i-1]);
            secondLastStepMin = lastStepMin;
            lastStepMin = newlastStepMin;
        }
        return lastStepMin;
    }
};