class Solution {
public:
    string generateString(string str1, string str2) {
        int n= str1.size();
        int m = str2.size();
        string ans(n+m-1, '*');

        for(int i=0;i<n; i++){
            if(str1[i]!= 'T') continue;

            for(int j=i;j<(i+m); j++){
                    if(ans[j] == '*'){
                        ans[j] = str2[j-i];
                    }
                    else if(ans[j] != str2[j-i]){
                        return "";
                    }
            }   
        }

        for(int i=0;i<n; i++){
            if(str1[i] != 'F') continue;
            int lastEmptyPos = -1;
            bool isMatch = true;
            for(int j=i;j<i+m;j++){
                char assumedChar =  (ans[j] == '*' ? 'a' : ans[j]);
                if(assumedChar != str2[j-i]){
                    isMatch = false;
                    break;
                }
                if(ans[j] == '*')lastEmptyPos = j;
            }
            if(isMatch){
                if(lastEmptyPos == -1) return "";
                ans[lastEmptyPos] = 'b';
            }
        }
        for(int i=0;i<m+n-1;i++){
            if(ans[i]=='*')ans[i]='a';
        }
        return ans;
    }
};