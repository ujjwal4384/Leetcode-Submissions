class Solution {

string s="";
// dp[idx][tight][leading_zero][mask][has_repeat]:divided [property] into two states
int dp[32][2][2][1024][2];   


public:
int solve(int idx, bool tight, bool leading_zero, int mask, int has_repeat){
        if(idx == s.size()){
            return has_repeat;
        }
        else if(dp[idx][tight][leading_zero][mask][has_repeat]!=-1) return dp[idx][tight][leading_zero][mask][has_repeat];
        
        int limit = (tight==1)? s[idx] - '0': 9;
        int ways = 0;

        for(int d=0;d<=limit;d++){
            if(leading_zero && d == 0) {
                // Leading zeros don't contribute to the mask or repeats
                ways += solve(idx + 1, tight & (d == limit), 1, 0, 0);
                continue;
            }
            bool next_tight = tight && (d==limit);
            int next_mask =  mask | 1<<d ;
            bool next_has_repeat = has_repeat ||  (mask & (1<<d)) ;
            ways +=  solve(idx+1, next_tight, 0, next_mask, next_has_repeat);
        }
        return dp[idx][tight][leading_zero][mask][has_repeat] = ways;
    }

    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof(dp));
        s = to_string(n);
        return solve(0, 1, 1,0, 0);
    }
};