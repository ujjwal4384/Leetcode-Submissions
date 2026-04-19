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
    bool checkIfValid(string text, string pattern){
        
        string str = pattern + "#" + text;
        vector<int> lps = kmp(str);
        for(int i=pattern.size()+1;i<str.size(); i++){
            if(lps[i] == pattern.size()) return true;
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        
        int n = a.size();
        int m = b.size();
        string pattern = b;
        string txt1 = a;
        int q = 1;
        while(txt1.size() < m)txt1 += a, q++;
        if(checkIfValid(txt1, pattern))return q;
        if(checkIfValid(txt1+a, pattern))return q+1;
        return -1;
    }
};