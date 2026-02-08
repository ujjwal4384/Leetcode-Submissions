class Solution {
public:
    int getCost(map<int,int>&freq, int& k){
        int cost = k;
        for(auto p:freq){
            if(p.second > 1) cost += p.second;
        }
        return cost;
    } 

    int f(int l, vector<int>& nums, int& k, vector<int>&dp){
        if(l>=nums.size()) return 0;
        else if(dp[l] !=-1) return dp[l];
        int mini = INT_MAX;
        int curCost = k;
        map<int,int>freq;
        for(int i=l;i<nums.size(); i++){
            freq[nums[i]] ++;
            if(freq[nums[i]] == 1){
                curCost += 0;
            }else if(freq[nums[i]]==2){
                curCost += 2;
            }else{
                curCost += 1;
            }
            int cost = curCost + f(i+1, nums, k, dp);
            mini = min(mini, cost);
        }
        return dp[l] = mini;
    }

    int minCost(vector<int>& nums, int k) {
        vector<int>dp(1001,-1);
        return f(0, nums, k, dp);
    }
};