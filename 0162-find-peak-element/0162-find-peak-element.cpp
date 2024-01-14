class Solution {
public:
    int findPeakElement(vector<int>& v) {
        //notice the constraints no tww adjacent characters can be same.
        //notice there will always be an answer.
        
        int n= v.size();
        if(n==1)return 0;
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(mid==0){ 
                if(v[mid]>v[mid+1])return mid;
                else low=mid+1;
            }
            else if(mid==n-1){
                if(v[mid]>v[mid-1])return mid;
                else high=mid-1;
            }
            
             
            else{
                if(v[mid]>max(v[mid-1],v[mid+1]))return mid;
                else{
                    if(v[mid-1]>v[mid]){
                        high=mid-1;
                    }else{
                        low=mid+1;
                    }
                }
            }
        }
      return -1;  
    }
};

