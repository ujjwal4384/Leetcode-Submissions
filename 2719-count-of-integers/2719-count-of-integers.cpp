class Solution {
    int MOD = 1e9+7;
    int min_sum ,max_sum;
  string s="";
    int dp[64][2][2][200] ; //dp[idx][tight][leading_zero][property]  
public:
    int solve(int idx, bool tight, bool leading_zero, int property){
        if(idx == s.size()){
            return property>=min_sum && property<=max_sum;
        }
        else if(dp[idx][tight][leading_zero][property] !=-1) return dp[idx][tight][leading_zero][property];
        
        int limit = (tight==1)? s[idx] - '0': 9;
        int ways = 0;

        for(int d=0;d<=limit;d++){
            ways = (0LL + ways + solve(idx+1, tight & (d == limit), leading_zero && (d==0), property + d) )%MOD;
        }
        return dp[idx][tight][leading_zero][property] = ways;
    }

    int count(string num1, string num2, int min_sum_, int max_sum_) {
        min_sum = min_sum_;
        max_sum = max_sum_ ;
         memset(dp, -1, sizeof(dp));
         s = num2;
         long long int countB = solve(0,1,1,0);

        memset(dp, -1, sizeof(dp));
        s = num1;
        long long int countA = solve(0,1,1,0);
         
      // 3. Check if num1 itself is valid
        int sum_num1 = 0;
        for (char c : num1) {
            sum_num1 += (c - '0');
        }
        bool isNum1Valid = (sum_num1 >= min_sum && sum_num1 <= max_sum);
        long long ans = (countB - countA + MOD) % MOD;
        if (isNum1Valid) {
            ans = (ans + 1) % MOD;
        }
     return ans;
    }
};