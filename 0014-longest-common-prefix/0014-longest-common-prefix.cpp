class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        for(int i=0;i<v[0].size();i++){
            for(auto&s:v){
                if(s[i]!=v[0][i]){
                   return ans;
                }
            }
            ans+=v[0][i];
        }
       return ans ;
    }
};