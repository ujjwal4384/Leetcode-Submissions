class Solution {
public:
    void f(int open, int close, string s, vector<string>&res){
        if(open == 0 && close == 0){
            res.push_back(s);
            return;
        }

        if(open > close){
            return ;
        }
        if(open){
            f(open-1, close, s+"(", res);
        }
        if(close){
            f(open, close-1, s+")", res);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string s="";
        f(n, n, s, res);
        return res;
    }
};