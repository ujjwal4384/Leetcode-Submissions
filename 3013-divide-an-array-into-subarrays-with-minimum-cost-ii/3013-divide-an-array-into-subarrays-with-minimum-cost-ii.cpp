#define ll long long
class Solution {
public:
    //1 2 3 4 5 6 7 8 9 10
    //k=6, d = 5
    long long minimumCost(vector<int>& nums, int k, int d) {
        int n=nums.size();
        k--;
        ll int cost=nums[0];
        
        int st_2 = 1,st_k = st_2+d;
        multiset<int>mini, rem;
        //first window [st_2, sr_k];
        for(int i=st_2;i<=st_k;i++){
            mini.insert(nums[i]);
            cost+=nums[i];
        }
        
        while(mini.size()>k){
            auto it= --mini.end();
             cost-= *it;
            rem.insert(*it);
            mini.erase(it);
           
        }
       
        ll int ans=cost;
        //sliding window
        for(int i= st_k+1;i<n;i++){
              int removeX = nums[i-d-1];
              int addX = nums[i];
              //STEP-1: removal of previous element
             // if el to be removed is present in mini , remove it from mini multiset
              if(mini.find(removeX)!=mini.end()){
                  cost-=removeX;
                  mini.erase(mini.find(removeX));
              }else{
                  //el is from rem multiset.
                  rem.erase(rem.find(removeX));
              } 
            
            //STEP-2: Addition of new element
            //if new element is lesser than largest element in mini set, he deserves to be in mini set
             
             if(addX < *(--mini.end())){
                    mini.insert(addX);
                 cost+= addX;
             }
             //else add in rem set
             else{
                 rem.insert(addX);
             }
            
             //balance the two arrays , means rem should contain k elements, after every iteration it might have k-1, k, k+1
            if(mini.size()<k){
                cost+= *rem.begin();
                 mini.insert(*rem.begin());
                 rem.erase(rem.begin());
               
            }else if(mini.size()>k){
                 cost-= *(--mini.end());
                rem.insert(*(--mini.end()) );
                mini.erase(--mini.end());
            }
            
          
            ans=min(ans, cost);
        }
        
       return ans; 
    }
};