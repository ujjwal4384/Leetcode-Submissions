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

    string shortestPalindrome(string s) {
        /*
         LOGIC: we just have to find current prefix of s which is alresady palindrome.
         //so that we can take remaining leftover suffix of s reveerse it and then add it in front.
         now to do that if we use dp[][] to find all substr which are palindrome or not
         and then pick substr starting from st=0 and pick max length valid dp[][]. 
         it iwl be n^2.
         s.length is <=1e4.
         therefore. use KMP.
         // prefix will match it's reverse if it is palindrome.
         // str = s + "#" + rev(s)
         // if last index of text has lps = 3 it means first three chars substr are palindrome already
        */
        int n = s.size();
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string str = s + '#' + rev_s;
        vector<int>lps = kmp(str);
        int len = lps.back();
        cout<<"len ="<<len<<endl;
        string remaining_s = s.substr(len, n-len);
        reverse(remaining_s.begin(), remaining_s.end());
        return remaining_s + s;
    }
};