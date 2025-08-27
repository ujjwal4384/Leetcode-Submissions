class Solution {
public:
    int f(int k, int i, int j,string& s1, string& s2, string& s3, int dp[201][101][101]){
        if(k>=s3.size()) return true;
        if(i>= s1.size() && j>= s2.size())return false;
        if(i>= s1.size()) return s3.substr(k) == s2.substr(j);
        if(j>= s2.size()) return s3.substr(k) == s1.substr(i);
        if(dp[k][i][j] !=-1) return dp[k][i][j];

        bool f1 = false, f2= false;
        if(s3[k] == s1[i]){
                f1 = f(k+1, i+1, j, s1, s2, s3, dp);
        }if(s3[k] == s2[j]){
                f2 = f(k+1, i, j+1, s1, s2, s3, dp);
        }
        dp[k][i][j] = (f1 || f2) ? 1 : 0;
     
        return dp[k][i][j] ;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int dp[201][101][101];
        if (s1.size() + s2.size() != s3.size()) return false; 
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,s1,s2,s3, dp);
    }
};