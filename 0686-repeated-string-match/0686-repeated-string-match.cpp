class Solution {
public:
    vector<int> kmp(string& s){
        int n = s.size();
        vector<int>lps(n, 0);
        int i=1;
        int len = 0;
        while(i<n){
             if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
             }else{
                  if(len!=0) len = lps[len-1];
                  else i++;
             }
        }
      return lps;
    }
    // bool checkIfValid(string text, string pattern){
        
    //     string str = pattern + "#" + text;
    //     vector<int> lps = kmp(str);
    //     for(int i=pattern.size()+1;i<str.size(); i++){
    //         if(lps[i] == pattern.size()) return true;
    //     }
    //     return false;
    // }

    int repeatedStringMatch(string a, string b) {
        
        int n = a.size();
        int m = b.size();
        string pattern = b;
        vector<int>lps = kmp(pattern);
        //simulate repeated a using modulo.  e.g a[i] -> a=[i%n];
        // for valid b - b must start from first copy of a -> 0, n-1. 
        int i=0, j=0;
        while(i< n+m){
             if(a[i%n] == b[j]){
                    i++, j++;
                    //match found
                    if(j==m){
                        return (i+n-1)/n;
                    }
             }else{
                   if(j!=0) j = lps[j-1];
                   else i++;
             }
        }
        return -1;
    }
};