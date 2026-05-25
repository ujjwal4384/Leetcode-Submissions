class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int prefix_mini= prices[0];
        for(int i=1;i<prices.size(); i++){
             maxi = max(maxi, prices[i] - prefix_mini);
             prefix_mini = min(prefix_mini, prices[i]);
        }
        return maxi;
    }
};