class Solution {
public:
    int MOD = 1e9+7;
//     int f(int pos, int n){
//         if(pos==n){
//             return 1;
//         }
//         if(pos%2){
//             return ( (4LL%MOD) * (f(pos+1, n)%MOD) + MOD)%MOD ;
//         }else{
//             return ( (5LL%MOD) * (f(pos+1, n)%MOD) + MOD)%MOD;
//         }
        
//     }
    long long myPow(long long x, long long n) {
        long long x_sign= x>=0?1:-1;
        long long n_sign= n>=0?1:-1;
        long long original_n = n;
        long long ans = 1;
        if(n==0)return ans;
        else if(x==0) return 0;
        x=abs(x);
        while(n){
            if(n%2){
                ans=(ans*x + MOD)%MOD;
            }
                x=( ( (x%MOD) * (x%MOD) ) + MOD) %MOD;
            
            n/=2;
        }
       if(n_sign==-1)ans=1/ans;
       if(x_sign==-1)ans= original_n%2?-1*ans:ans;
       return ans; 
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (1+n)/2;
        int even_choice = 5;
        int odd_choice = 4;
        long long a = myPow(even_choice, even);
        long long b = myPow(odd_choice, odd);
        long long res = ((a%MOD) * (b%MOD) + MOD )%MOD;
        return (int)res;
    }
};