class Solution {
    int f(int i, int j, string&s1, string&s2, int dp[][502]){
        //BASE CASE
        if(i==s1.size()){
            return (s2.size() - j);
        }else if(j==s2.size()){
            return (s1.size() - i);
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int ans =1e7;   
        if(s1[i]==s2[j]){
            ans= 0 + f(i+1, j+1, s1, s2, dp);
        }else{
            int a= 1 + f(i+1, j, s1, s2, dp);
            int b= 1 + f(i, j+1,s1,s2, dp);
            ans=  min(a, b);   
        }
        return dp[i][j]=ans;
    };
public:
    int minDistance(string word1, string word2) {
         int dp[502][502];
          memset(dp, -1, sizeof(dp));
         int a= f(0,0,word1, word2, dp);
         return a;
    }
};