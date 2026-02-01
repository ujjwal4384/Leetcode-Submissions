class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=i+1; j<n; j++){
                int a = nums[0], b= nums[i], c= nums[j];
                int sum = a+b+c;
                minSum = min(minSum, sum);
            }
        }

        return minSum;
    }
};