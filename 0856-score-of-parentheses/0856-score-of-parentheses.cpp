class Solution {
public:
    int scoreOfParentheses(string s) {
         stack<int>st;
         //We use the stack to hold the running score of each unfinished layer.
         st.push(0); //base layer to hold final total.
         for(auto x:s){
            if(x=='('){
                //eneter a new layer
                st.push(0);
            }else{
                //child layer score reoslved. merge to parent's running score
                int top = st.top();
                st.pop();
                int add = top > 0 ? 2*top : 1;
                st.top() += add;
            }
         }
         return st.top();
    }
                                                                                                                                                   
};