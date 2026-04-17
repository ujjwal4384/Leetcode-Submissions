class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open = 0;
        for(auto&x: s){
            if(x == '('){
                if(open>0)ans += x;
                open++;
            }else{
                if(open > 1) ans += x;
                open--;   
            }
        }
        return ans;
    }
};