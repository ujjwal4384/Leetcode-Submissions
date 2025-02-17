class Solution {
public:

    int solve(string& num, int N, bool takeBoth, bool tight,int dp[33][2][2] ){
        if(N==1){
            return takeBoth==false ? 1 : ( tight ? (num[num.size()-N]-'0') + 1 :2);
        }
        else if(dp[N][takeBoth][tight] !=-1) return dp[N][takeBoth][tight];

        int ub = ( tight ? (num[num.size()-N]-'0') :1);
        int count = 0;

        for(int dig =0; dig<=ub; dig++){
              if(dig==1 && takeBoth==false){
                continue;
              }
              count +=   solve(num, N-1, dig==0?true:false, tight && dig==ub, dp);
        }

        return dp[N][takeBoth][tight] = count;
    }

    int findIntegers(int n) {
        string s = "";
        int dp[33][2][2];
        
        memset(dp,-1, sizeof(dp));

        for(int bit = 0; bit<32; bit++){
            int p = (1<<bit);
            if(n&p){
                s = '1' + s;
               
            }else{
                s = '0' + s;
            }
        }
        
        
      
        int ans = solve(s, s.size(), true, 1, dp);
    
        return ans;
    }
};