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
    int strStr(string haystack, string needle) {
            string s = needle + "#" + haystack;
            vector<int>lps = kmp(s);
           
            for(int i= needle.size()+1; i<s.size(); i++){
                    if(lps[i] == needle.size()) {
                        
                        return (i-needle.size()-1) - (needle.size()-1);
                    }
                    
            }      
            return -1;
    }
};