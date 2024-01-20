class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int n= nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<mini)mini=nums[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++)cnt+=(mini==nums[i]);
        
        if(cnt==1) return 1;
        
        else{
        //check if any num which y%mini>0 bcz then that will be less tha mini hence ans=1
          for(int i=0;i<n;i++){
              if(nums[i]==mini)continue;
              else{
                  if(nums[i]%mini)return 1;
              }
          }    
           return cnt/2 + (cnt%2 ? 1 : 0) ;
        }
    }
};
//minimum -> once->1 ans, else 
//check if any num s.t. y%x>0 bcz => y%x<x so new minima  => 1 answer
//else ans = cnt(min)/2 + odd?1:0