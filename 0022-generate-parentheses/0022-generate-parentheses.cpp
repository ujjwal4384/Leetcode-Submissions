class Solution {
public:
    void f(int left, int right, string s, vector<string>&res){
        if(left==0 && right==0){
            res.push_back(s);
            return;
        }
        
        else if(left>right){
            return ;
        }

        if(right){
            f(left, right-1, s+")", res);
        }
        if(left){
            f(left-1, right, s+"(", res);
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        
        string s=""; 
        f(n,n, s, res);   
        return res;
    }
};