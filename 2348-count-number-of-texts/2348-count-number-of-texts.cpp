class Solution {
public:
    const long long int MOD = 1e9 + 7; 
    bool isValid(string&s){

        int sz = s.size();
        if(sz <=0 || sz>4) return false;
        
        //now check if all letters are same or not
        for(int i=1;i<sz ;i ++){
            if(s[i] != s[i-1]) return false;
        }

        if(sz <=3) return true;

        if(sz ==4 && (s[0] == '7'|| s[0] =='9') ) return true;
        
      return false;  
    }

    int countTexts(string s) {
        int n = s.size();
        long long int * dp = new long long int[n+1];
        // fill_n(dp, n+1, -1);
        // return f(0, s, dp);
        
        fill_n(dp, n+1, 0LL);
        
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){

            string t = "";
            long long int count = 0;
            for(int k=i; k< min(n, i+4); k++){
                t += s[k];
                bool flag = isValid(t);
                if(flag){
                    count = (count%MOD + dp[k+1]%MOD)%MOD;
                }
                
            }
            dp[i] = count%MOD;
        }

       return (int) dp[0]%MOD; 
    }
};