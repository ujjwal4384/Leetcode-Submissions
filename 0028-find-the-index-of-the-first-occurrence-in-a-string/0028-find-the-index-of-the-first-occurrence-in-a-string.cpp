class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= haystack.size();
        int m= needle.size();
        
        for(int i=0; i<n; i++){
            if(haystack[i]==needle[0]){
                int j=i; 
                int k=0;
                while(j<n && k<m){
                    if(haystack[j]==needle[k]){
                        j++;
                        k++;
                    }else{
                        break;
                    }
                }
                if(k==m)return i;
               
            }    
        }

      return -1;  
    }
};