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
            
            vector<int>lps = kmp(needle);
           
            int i=0, j=0;
            vector<int>ans;
            while(i<haystack.size()){
                      if(haystack[i] == needle[j]){
                               i++, j++;
                               if(j==needle.size()){
                                    ans.push_back(i-j);
                                    j = lps[j-1];
                               }       
                      }else{
                            if(j!=0) j = lps[j-1];
                            else i++;
                      }
            }
            return ans.size() > 0 ? ans[0] : -1;
    }
};