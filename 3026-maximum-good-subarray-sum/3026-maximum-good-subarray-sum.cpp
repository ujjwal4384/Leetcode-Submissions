class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pre(n,0);
        for(int i=0;i<n;i++){
            if(i==0)pre[i]=nums[i];
            else pre[i]=pre[i-1]+nums[i];
        }
       
      
        map<int, vector<int>>mp;
        long long maxi=-1e17;
        long long s=0;
        for(int i=0;i<n;i++){
          
            s+=nums[i];
            vector<int>v={nums[i]-k, nums[i]+k};
            for(auto x:v){ 
                if(mp.find(x)!=mp.end()){
                     auto it=mp.find(x);

                     for(auto & id: it->second){
                        long long cur = s- (id==0?0:pre[id-1]);
                        maxi = max(maxi,cur); 
                     }

                }
            }
            mp[nums[i]].push_back(i);
        }
        
        return maxi==-1e17?0:maxi;
        
    }
};
