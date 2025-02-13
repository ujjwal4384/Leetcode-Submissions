



class Solution {
 multiset<int, greater<int>>ms1;
 multiset<int>ms2; 
   void addNum(int x){
        ms1.insert(x);
        int sz1 = ms1.size();
        int sz2 = ms2.size();

        if(sz1 - sz2 > 1){
            auto it1 = ms1.begin();
            ms2.insert(*it1);
            ms1.erase(it1);
        }
        else if(sz2 >0 && ( (*ms1.begin()) > (*ms2.begin()) ) ){
            //rebalance 
            int x1 = *ms1.begin();
            ms2.insert(x1);
            ms1.erase(ms1.begin());

            int x2 = *ms2.begin();
            ms1.insert(x2);
            ms2.erase(ms2.begin());
        }
};
void removeNum(int x){
        if(x <= (*ms1.begin()) ){
            ms1.erase(ms1.find(x));
        }else{
            ms2.erase(ms2.find(x));
        }

        if(ms2.size() > ms1.size()){
            ms1.insert(*ms2.begin());
            ms2.erase(ms2.begin());
        }
}; 
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int sz = n-k+1;
        vector<double>ans(sz, 0);
        
        if(k==1){
            for(int i=0; i<n;i++)ans[i]=nums[i];
            return ans;
        }

        int p = k/2;
        
        for(int i=0;i<k;i++){
            ms1.insert(nums[i]);
        }

        
        while(p>0){
            ms2.insert(*ms1.begin());
            ms1.erase(ms1.begin());
            p--;
        }
       
    
       int j = k-1; 
       while(j<n){        
         int sz1 = ms1.size();
         int sz2 = ms2.size();
         int x1 = *ms1.begin();
         int x2 = *ms2.begin();
        
         ans[j-(k-1)] =  k%2 ? (*ms1.begin()) :  (0LL + x1 + x2)/2.0 ; 
     
         if(j==n-1){
            break;
         }

         removeNum(nums[j-(k-1)]);   
         
         j++;

         addNum(nums[j]);   

       }

       return ans;
    }
};