class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size();
        if(n<=1) return 0;
        int l=0,r=n-1;
        while(l<=r){
               int m = (l+r)/2;
               if(m==0){
                   if(arr[0]<arr[1])
                     l=m+1; 
                   else return m;  
               }else if(m==n-1){
                   if(arr[m-1] < arr[m-2])
                    r= m-1;
                    else return m;
               }else{

                  if(arr[m]>arr[m-1] && arr[m]> arr[m+1]){
                    return m;
                  }
                  else if(arr[m]<arr[m+1]){
                       l=m+1;
                  }else{
                    r=m-1;
                  }

               } 
        }

        return -1;
    }
};