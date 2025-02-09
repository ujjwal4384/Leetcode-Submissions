class Solution {
public:
    const long long int MOD = 1e9 + 7;
    long long int validWays(string&s){
        int sz = s.size();
        if(sz == 0 || sz>2)   return 0;
        
        if(sz==1){
            if(s=="*"){
                return 9;
            } else{
                return s>"0" && s<="9" ? 1 : 0;
            }
        }

        else if(sz==2){
            if(s=="**"){
                //if first char is 1 ways = 9 (11->19)
                //if firs char is 2 ways = 6  (21->26)
                return 9 + 6;
            }
            else if(s[0]=='*'){
                //second number is fixed here (anything  0 to 9)
                //if first char is 1 ways = 1 (10->19)
                 //if first char is 2 ways = 1 if second char is <=6 else 0.
                 //hence total ways = s[1]<='6' ? 2 : 1;
                 return s[1] <='6' ? 2 : 1; 
            }else if(s[1] == '*'){
                if(s[0] == '0' || s[0]> '2') return 0;
                else if(s[0] == '1'){
                    return 9;
                }else if(s[0] == '2'){
                    return 6;
                }
            } else{
                //no *, both numbers fixed 
                return s[0] > '0' && s>"0" && s <="26" ? 1: 0;
            }
        }

      return 0;  
    }

    int numDecodings(string s) {
        int n = s.size();
        long long int* dp = new long long int[n+1];
       
        
        fill_n(dp, n+1, 0LL);
        
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){

            string t = "";
            long long int count = 0;
            for(int k=i; k< min(n, i+2); k++){
                t += s[k];
                int ways = validWays(t);
                if(ways){
                    count = (count%MOD +  (1LL * ways* dp[k+1])%MOD ) % MOD;
                }
                
            }
            dp[i] = count;
        }

       return (int) dp[0] % MOD; 
    }
};