class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long ops = 0;
        sort(nums.begin(), nums.end());

        int n= nums.size();
        
        int i = n/2;
        
        if(nums[i] >k){
                ops = abs(k-nums[i]);
                while(i-1>=0 && nums[i-1]>k){
                    ops += abs(k-nums[i-1]);
                    i--;
                }
        }else{
                ops = abs(k-nums[i]);
                while(i+1<n && nums[i+1]<k){
                    ops += abs(k-nums[i+1]);
                    i++;
                }
        }
        
        return ops;
        
    }
};