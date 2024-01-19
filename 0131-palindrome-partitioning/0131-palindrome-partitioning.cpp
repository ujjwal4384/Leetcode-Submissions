class Solution {
public:
    bool isPalindrome(string&str){
        int n= str.size();
        int l=0,r=n-1;
        while(l<r){
            if(str[l]!=str[r])return false;
            l++,r--;
        }
        return true;
    }
    void f(int pos, string&s, vector<vector<string>>&res, vector<string>v ){
        if(pos==s.size()){
            res.push_back(v);
            return;
        }
        string temp="";
        for(int k = pos;k<s.size();k++){
            temp += s[k];
            if(isPalindrome(temp)){
                 v.push_back(temp);
                 f(k+1,s, res, v);
                 v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>v;
        f(0, s, res, v);
        return res;
    }
};