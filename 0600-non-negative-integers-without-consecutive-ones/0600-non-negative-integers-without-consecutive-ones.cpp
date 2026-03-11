class Solution {
       string s="";
    
    int dp[32][2][2][2] ; //dp[idx][tight][leading_zero][property]   
public:
int solve(int idx, bool tight, bool leading_zero, int property){
        if(idx == s.size()){
            return 1;
        }
        else if(dp[idx][tight][leading_zero][property] !=-1) return dp[idx][tight][leading_zero][property];
        
        int limit = (tight==1)? s[idx] - '0': 1;
        int ways = 0;

        for(int d=0;d<=1;d++){
            if(tight && (d >limit)) {
                continue;
            }
            if(d==1 && property==1 && leading_zero ==0) continue;
            ways +=  solve(idx+1, tight & (d == limit), leading_zero && (d==0), d);
        }
        return dp[idx][tight][leading_zero][property] = ways;
    }

    int findIntegers(int n) {
        memset(dp, -1, sizeof(dp));
        int temp = n;
        while(temp > 0) {
            s += to_string(temp % 2);
            temp /= 2;
        }
        reverse(s.begin(), s.end());
        return solve(0,1,1,0);
    }
};