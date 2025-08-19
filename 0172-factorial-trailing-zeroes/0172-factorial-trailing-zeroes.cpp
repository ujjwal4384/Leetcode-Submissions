class Solution {
public:
    int trailingZeroes(int n) {
        int num = n;
        int a = 0;
        int b = 0;
      for(int number=n;number>=1;number--){
        int num = number;
        while(num>0 && num%2==0){
            num/= 2;
            a++;
        }

        num = number;
        
        while(num>0 && num%5==0){
            num/= 5;
            b++;
        }
      }  
        
      return min(a, b);  
    }
};