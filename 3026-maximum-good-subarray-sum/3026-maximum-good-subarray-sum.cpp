class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long int>pre(n,0LL);
        for(int i=0;i<n;i++){
            if(i==0)pre[i]=nums[i];
            else pre[i]=pre[i-1]+nums[i];
        }

        
        unordered_map<int, vector<int>>mp;
        
        long long int maxi= -1e17;
        long long int s=0;

        for(int i=0;i<n;i++){
          
            s+=nums[i];
          
            for(auto x : {nums[i]-k, nums[i]+k}){
                     for(auto & id: mp[x]){
                        long long cur = s- (id==0?0:pre[id-1]);
                         maxi = max(cur, maxi); 
                     }
            }
            
            mp[nums[i]].push_back(i);
        
        }
             
        
       
        
        return maxi== -1e17 ? 0 : maxi;
        
    }
};
