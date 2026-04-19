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

    bool repeatedSubstringPattern(string s) {
            vector<int>lps = kmp(s);
            int suffMatchLength = lps.back();
            int substrLength = s.size() - suffMatchLength;
            return suffMatchLength>0 && (s.size()%substrLength ==0);
    }
};