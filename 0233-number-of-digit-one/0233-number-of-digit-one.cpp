class Solution {
      string s="";
    int dp[32][2][2][10] ; //dp[idx][tight][leading_zero][property]  
public:
    int solve(int idx, bool tight, bool leading_zero, int property){
        if(idx == s.size()){
            return property;
        }
        else if(dp[idx][tight][leading_zero][property] !=-1) return dp[idx][tight][leading_zero][property];
        
        int limit = (tight==1)? s[idx] - '0': 9;
        int ways = 0;

        for(int d=0;d<=9;d++){
            if(tight && (d >limit)) {
                continue;
            }
            ways += solve(idx+1, tight & (d == limit), leading_zero && (d==0), property + (d==1));
        }
        return dp[idx][tight][leading_zero][property] = ways;
    }
    int countDigitOne(int n) {
         memset(dp, -1, sizeof(dp));
         s = to_string(n);
         return solve(0, 1,1,0);
    }
};