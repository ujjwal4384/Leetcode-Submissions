class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
            if(i+1<n && s[i] == s[i+1])dp[i][i+1] = 1; 
        }

        for(int len = 3;len<=n; len++){
            int st =0, en = len-1;
            while(en<n){
                 dp[st][en] = (s[st]==s[en]) && dp[st+1][en-1] ;
                 st++, en++;
            }
        }

        for(int len = n;len>=1;len--){
            int st = 0, en = len-1;
            while(en<n){
               if(dp[st][en]) return s.substr(st, en-st+1);
               st++, en++;
            }
        }
        return "";
    }
};