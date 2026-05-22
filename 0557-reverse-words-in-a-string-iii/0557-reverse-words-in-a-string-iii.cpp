class Solution {
public:
    string reverseWords(string str) {
         int n = str.size();
    // reverse(str.begin(), str.end());
     
    int i=0;
    while(i<n){
        while(i<n && str[i] == ' ')i++;
        if(i>=n)break;
        int l = i;
        while(i<n && str[i] != ' ')i++;
        int r = i-1;
        reverse(str.begin()+l,str.begin()+r+1);
    }
    return str;
    }
};