class Solution {
public:
    string getRLE(string& str){
        string ans ="";
        int n = str.size();
        int i=0;
        while(i<n){
            char ch = str[i];
            int j = i+1;
            while(j<n && str[j] == ch)j++;
            ans += to_string(j-i) + ch;
            i = j;
        }
        return ans;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        string str = countAndSay(n-1);
        return getRLE(str);
    }
};