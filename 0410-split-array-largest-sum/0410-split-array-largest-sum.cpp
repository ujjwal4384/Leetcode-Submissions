class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int m){
        int curSum =0;
        int part=1;
        for(int i=0;i<nums.size();i++){
            // if(nums[i]>m) return false;
            if(curSum+ nums[i]<=m){
                curSum+= nums[i];
            }else{
                curSum = nums[i];
                part++;
            }
        }

        return part <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int sum=0,  maxi=INT_MIN;
        for(auto&x:nums){
            sum+=x;
            maxi = max(maxi, x);
        }

        int l = maxi, r=sum;

        while(l<r){
            int m = l + (r-l)/2;

            if(isPossible(nums, k, m)){
                r=m;
            }else{
                l=m+1;
            }
        }

         return l;
    }
};