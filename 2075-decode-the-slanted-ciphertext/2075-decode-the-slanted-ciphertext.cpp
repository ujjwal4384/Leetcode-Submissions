class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int mn = encodedText.size();
        int m= rows , n= mn/m;
        string ans = "";
        int j= 0;
        while(j<n){
            int r = 0, c =j;
                while(r<m && c<n){
                      ans += encodedText[n*r + c];  
                      r++, c++;
                }
                j++;
        }
        
        int i = ans.size()-1;
        while(i>=0 && ans[i]== ' '){
            i--;
        }
        return ans.substr(0, i+1);
    }
};