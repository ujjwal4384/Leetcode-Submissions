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
        
        long long int maxi= 0;
        long long int s=0;
        bool flag=false;
        for(int i=0;i<n;i++){
          
            s+=nums[i];
          
            for(auto x : {nums[i]-k, nums[i]+k}){
               
                if(mp.find(x)!=mp.end()){
                     auto it=mp.find(x);
                   
                     for(auto & id: mp[x]){
                        long long cur = s- (id==0?0:pre[id-1]);
                         if(!flag)maxi=cur;
                         else maxi = max(cur, maxi); 
                         flag=true;

                     }

                
                }
            }
            
            mp[nums[i]].push_back(i);
             
        }
        if(!flag) return 0;
        
        return maxi;
        
    }
};
