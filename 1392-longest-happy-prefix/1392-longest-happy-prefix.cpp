class Solution {
public:
    vector<int> kmp(string& s){
        
         int n = s.size();
         vector<int>lps(n, 0);
         int i = 1, len = 0;
         while(i<n){
             if(s[i] == s[len]){
                len ++;
                lps[i] = len;
                i++;
             }else{
                   if(len!=0)len = lps[len-1];
                   else i++;
             }
         }
         return lps;
    }

    string longestPrefix(string s) {
           int n =s.size();
           vector<int>lps = kmp(s);
            int len = lps.back();
          
        return len == 0 ? "" : s.substr(n- len, len);          
    }
};