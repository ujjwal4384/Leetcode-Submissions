class Solution {
    vector<int> kmp(string&s){
        int n = s.size();
        vector<int>lps(n,0);

        int i=1,len=0;
        while(i<n){
             if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
             }else{
                if(len!=0)len = lps[len-1];
                else i++;
             }
        }
     return lps;   
    }
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();
        string pattern = b;
        vector<int>lps = kmp(pattern);
        //how many copies of a will be needed at max? b length / a length ceil. 
        //instead of creating multiple copies of a to iterate- use modulo for cicular iteration/
        //if there is possbility- then b's first char should match a in first copy only. in worsrt case at last char of a = b ka first character.
        //after that j will go m  characters. therefore i till> n-1 + m. if no match found until there also, then not posssible.

        int i=0,j=0;
        while(i<m+n-1){
                if(a[i%n] == b[j]){
                     i++, j++;
                     //match found
                     if(j==m){
                        //calculate number of copies of a=> total chars of a used and length of one copy
                        return ceil((0.0+i)/n);
                     }
                }else{
                    if(j!= 0) j = lps[j-1];
                    else i++;
                }    
        }
        return -1;
    }
};