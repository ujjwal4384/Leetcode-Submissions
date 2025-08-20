class Solution {
public:
    double f(double x, long long n){
        if(x==0) return 0;
        if(x==1) return 1;
        if(n==0) return 1;

        double multiplier = (n%2==1) ? x : 1;
        
        x *= x;
        n /= 2;
        return  multiplier * f(x, n);
    }

    double myPow(double x, int _n) {
         long long int n = _n;

         if(n<0){
            x = 1/x;
         }
         n= abs(n);
         int sign = (x<0 && n%2) ? -1 : 1;
         x = abs(x);
         double res = f(x, n);        
      
        return sign * res;
    }
};