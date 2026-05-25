class Solution {

    int f(int i, int j, string&s1, string&s2, int dp[][502]){
        //BASE CASE
        if(i==s1.size() || j==s2.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int ans =INT_MIN;   
        if(s1[i]==s2[j]){
            ans= 1 + f(i+1, j+1, s1, s2, dp);
        }else{
            int a= f(i+1, j, s1, s2, dp);
            int b= f(i, j+1,s1,s2, dp);
            ans=  max(a, b);   
        }
        return dp[i][j]=ans;
    };
public:
    int minInsertions(string s) {
        int dp[502][502];
        memset(dp, -1, sizeof(dp));
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int a= f(0,0,s, s2, dp);
        return s.size() - a;
    }
};