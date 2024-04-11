class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int miniAbsDif =INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target) return sum;
                
                int curAbsDif = abs(sum - target);
                if(curAbsDif< miniAbsDif){
                    miniAbsDif = curAbsDif;
                    ans = sum;
                }
                if(sum<target)j++;
                else k--;
            }
        }
       return ans; 
    }
};