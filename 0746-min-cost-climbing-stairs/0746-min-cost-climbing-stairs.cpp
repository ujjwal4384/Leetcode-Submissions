class Solution {
public:
    int f(int i, int dp[],vector<int>& cost){
        if(i==0 || i==1) return 0;
        if(dp[i]!=-1) return dp[i];    
        int way1= INT_MAX,way2=INT_MAX;
        if(i-1>=0)way1 = cost[i-1] + f(i-1, dp, cost); 
        if(i-2>=0) way2 = cost[i-2] + f(i-2, dp, cost);
        return dp[i] =  min(way1, way2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int* dp= new int[n+1];
        for(int i=0;i<n+1;i++)dp[i]=-1;
        return f(n, dp, cost);
    }
};