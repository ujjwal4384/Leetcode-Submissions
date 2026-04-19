class Solution {
public:
    int reverseNum(int n){
         int rev_n =0;
         while(n){
             rev_n = rev_n*10 + (n%10) ;
             n /= 10;
         }
         return rev_n ;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int>mp;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
                
                if(mp.count(nums[i])){
                          ans = min(ans, i - mp[nums[i]]);           
                }
                int rev_n = reverseNum(nums[i]);
                mp[rev_n] = i;              
        }
        return ans == INT_MAX ? -1 : ans;
    }
};