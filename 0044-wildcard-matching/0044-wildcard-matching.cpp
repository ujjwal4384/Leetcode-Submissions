class Solution {
    bool f(int i, int j, string&s, string& p, vector<vector<int>>&dp){
        int m = s.size(), n = p.size();
        if(i>=m && j>=n) return true;
        else if(i<m && j>=n) return false;
        else if(i>=m && j < n) {
              for(auto k=j;k< n;k++){
                if(p[k] != '*') return  false;
              }
              return  true;
        }
        else if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = f(i+1, j+1, s, p, dp);
        }

        else if(p[j] == '*'){
             //can consider this to be rmeoved., or match one character of s and let j still stay there only becasue * can match any continguous length string
             return dp[i][j] = f(i+1, j, s, p, dp) || f(i, j+1, s, p, dp);
        }
        return dp[i][j] = false; //means char donot match and are no special chars also
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return f(0, 0,s,p, dp) ==1 ? true : false;
    }
};