class Solution {
public:
    double myPow(double x, int n) {
        int x_sign= x>=0?1:-1;
        int n_sign= n>=0?1:-1;
        int original_n = n;
        double ans = 1;
        if(n==0)return ans;
        else if(x==0) return 0;
        x=abs(x);
        while(n){
            if(n%2){
                ans*=x;
            }
                x*=x;
            
            n/=2;
        }
       if(n_sign==-1)ans=1/ans;
       if(x_sign==-1)ans= original_n%2?-1*ans:ans;
       return ans; 
    }
};


// 2^30=> (4)^15=> 4*4^14=> 4* (16)^7;