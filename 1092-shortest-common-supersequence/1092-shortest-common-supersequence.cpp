class Solution {
 int f(int i, int j, string&s1, string&s2, int dp[][1002]){
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
    string shortestCommonSupersequence(string str1, string str2) {
        int dp[1002][1002];
          memset(dp, -1, sizeof(dp));
         int lcs= f(0,0,str1, str2, dp);
         //shortest superseuqnece =  m+n - lcs_length
         //because common guys we only add once. 
         int m = str1.size(), n = str2.size();
         string ans= "";
         int i=0,j=0;
         while(i<m && j<n){
               if(str1[i] == str2[j]){
                   ans += str1[i];
                   i++, j++;
                   //yu are leavining both behind, since both char are same take it only once
                   continue;
               } 
               int a= i+1 < m ? dp[i+1][j] : 0;
               int b= j+1<n ? dp[i][j+1] : 0;
               if(a>b){
                //on moving i++ you leave str1[i] behind , so include it in ans
                     ans += str1[i];
                     i++;   
               }else{
                    ans += str2[j];
                    j++;
               }
         }

         if(i <m){
             ans += str1.substr(i);
         }
         else if(j < n){
            ans += str2.substr(j);
         }

         return ans;
    }
};