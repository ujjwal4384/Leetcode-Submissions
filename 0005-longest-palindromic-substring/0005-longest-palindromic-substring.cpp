class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[1001][1001];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
            if(i+1<n&&s[i]==s[i+1])dp[i][i+1] = 1;
        }

        //for 3 length to n length string
          for(int len =3;len<=n;len++){
             int st = 0,en=len-1;
             while(en<n){
                if(dp[st+1][en-1] && s[st]==s[en]){
                    dp[st][en]=1;
                }
                st++,en++;
             }
          }
       
        //find longest palindromic string
         for(int len =n;len>=1;len--){
             
             int st=0,en=len-1;
             while(en<n){
             
                if(dp[st][en]){
                    return s.substr(st, len);
                }
                st++,en++;
             }
         }
         return "";           
    }
};