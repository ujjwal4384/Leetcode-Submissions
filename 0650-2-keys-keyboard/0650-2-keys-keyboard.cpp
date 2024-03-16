class Solution {
public:
    int minSteps(int n) {
        //  dp[i]= min ops required to have i characters of 'A'
        //example- dp[24]
        //approach: last step always paste ka hoga. 
        //what are possible penultimate state? either 12 characters of A then we paste 12 one time
        //OR 6 characters of A and we paste 6 three times, smilarly 4 => factors of 24 states.
        
        //dp[i] = min(dp[j]+ cnt(j->i by pasting)) j= factors of i
        //cnt(j->i by pasting ) (i/j)-1;
       int* dp= new int[1001];
        for(int i=0;i<n+1;i++)dp[i]=i;
        
        dp[1]=0;
        dp[2]=2;// 1 copy ops and 1 paste ops
        dp[3]=3;// 1 copy ops and 2 paste ops
        //for remaining we can achieve by 1 copy op of previous states data and pasting it k times.
        for(int i=4;i<=n;i++){
            for(int j=2;j<=n/2;j++){
                
                if(i%j==0){
                    dp[i] = min(dp[i], dp[j] + (i/j) );
                }
            }
        }
      return dp[n];  
    }
};
//i=6, j=2: i/j->3 4-> AA AA ->3