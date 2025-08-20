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
         int sign_n = n<0 ? -1 : 1;
         int sign = (x<0 && n%2) ? -1 : 1;
         
         double res = f(abs(x), abs(n));        
      

        if(sign_n == -1){
            res = 1/res;
        } 
        return sign * res;
    }
};