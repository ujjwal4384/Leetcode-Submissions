class Solution {
vector<int> dp;
public:
    int f(int i, vector<int>&v, int k){
        if(i==v.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxSoFar = 0;
        int ans = 0;
        for(int j=i;j<min(i+k, (int)v.size());j++){
            maxSoFar = max(maxSoFar, v[j]);
            int curCost = (j-i+1) * maxSoFar + f(j+1, v, k) ;
            ans = max(ans, curCost);
        }

        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        dp.assign(arr.size(), -1);
        return f(0, arr, k);
    }
};