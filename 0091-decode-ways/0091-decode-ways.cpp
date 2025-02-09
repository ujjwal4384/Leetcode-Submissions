class Solution {
public:
    bool isValid(string&s){
        int sz = s.size();
        switch(sz){
            case 0: 
               return false;
            case 1:
                return s > "0" && s<="9";
            case 2: 
                 return s[0] > '0' && s>"0" && s <="26";
            default:
                  return false;            
        }
      return false;  
    }
    
    int f(int i, string&s, int dp[]){
        if(i >= s.size()){
            return 1;
        }
        if(dp[i] != -1) return dp[i];

        string t = "";
        int count = 0;
        for(int k=i; k< s.size(); k++){
            t += s[k];
            bool flag = isValid(t);
            if(flag){
                count += f(k+1, s, dp);
            }
        }

        return  dp[i] = count;
    }
    int numDecodings(string s) {
        int n = s.size();
        int* dp = new int[n+1];
        fill_n(dp, n+1, -1);
        return f(0, s, dp);
    }
};