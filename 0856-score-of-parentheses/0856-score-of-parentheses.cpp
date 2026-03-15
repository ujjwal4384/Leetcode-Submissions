class Solution {
public:
    int scoreOfParentheses(string s) {
         
         int value = 0;
         int depth = 0;
         for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth ++;
            }else{
                depth --;
                if(s[i-1] == '(')
                value +=  (1<<depth);
            }
         }
         return value;
    }
                                                                                                                                                   
};