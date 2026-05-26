class Solution {
    int f(int i, vector<int>&arr, int d, vector<int>&dp){
        if(i>=arr.size() || i<0) return 0;
        if(dp[i] != -1) return dp[i];
        
        dp[i] = 1;
        int st = max(0,i-d);
        int en = min((int)arr.size()-1, i+d);
        //LEFT
        for(int k= i-1;k>=st; k--){
            if(arr[k] >= arr[i]) break;
            dp[i] = max(dp[i], 1 + f(k, arr, d, dp));
        }

        //RIGHT
        for(int k= i+1;k<=en; k++){
            if(arr[k] >= arr[i]) break;
            dp[i] = max(dp[i], 1 + f(k, arr, d, dp));
        }
        return dp[i];
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int>dp(n, -1);
        int maxi = 1;
        for(int i=0;i<n;i++){            
            int count = f(i, arr, d, dp);
            maxi = max(maxi, count);
        }
        return maxi;
    }
};