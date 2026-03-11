class Solution {
    string s="";
    vector<string>v;
    int dp[32][2][2] ; //dp[idx][tight][leading_zero][property]    
public:
    int solve(int idx, bool tight, bool leading_zero){
        if(idx == s.size()){
            return leading_zero ==1 ? 0 :1;
        }
        else if(dp[idx][tight][leading_zero] !=-1) return dp[idx][tight][leading_zero];
        
        int limit = (tight==1)? s[idx] - '0': 9;
        int ways = 0;

        if (leading_zero) {
            ways += solve(idx + 1, 0, 1); 
        }

        for(auto dig:v){
            int d = dig[0]- '0';
            if(tight && (d >limit)) {
                continue;
            }
            ways +=  solve(idx+1, tight & (d == limit), 0);
        }
        return dp[idx][tight][leading_zero] = ways;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        v = digits;
        memset(dp, -1, sizeof(dp));
        while(n>0){
            int rem = n%10;
            n/=10;
            s = (char)('0' + rem) + s; 
        }
        
        return solve(0,1, 1);
    }
};