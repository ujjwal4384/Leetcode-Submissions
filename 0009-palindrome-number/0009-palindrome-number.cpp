class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0) return false;
        long long int n=x;
      
        long long int rev_x=0;
        
        while(n){
             int rem = n%10;
             rev_x = rev_x*10 + rem;
             n/=10;
        }
        
     return x == rev_x;   
    }
};