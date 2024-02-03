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
        bool flag=false;
        for(int i=0;i<n;i++){
          
            s+=nums[i];
            int a=nums[i]-k,b=nums[i]+k;
           
            if(mp.find(a)!=mp.end()){
                 auto it=mp.find(a);
                
                 for(auto & id: it->second){
                     flag=true;
                    long long cur = s- (id==0?0:pre[id-1]);
                    if(cur>maxi) maxi = cur; 
                   
                 }
                
            }
            if(mp.find(b)!=mp.end()){
                
                 auto it=mp.find(b);
               
               
                 for(auto & id: it->second){
                       flag=true;
                    long long cur =s- (id==0?0:pre[id-1]);
                    if(cur>maxi) maxi = cur; 
                 }
               
                
            }
            mp[nums[i]].push_back(i);
             
        }
        if(!flag) return 0;
        
        return maxi;
        
    }
};
