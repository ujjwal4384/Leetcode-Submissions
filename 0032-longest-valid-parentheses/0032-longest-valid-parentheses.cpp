class Solution {
public:
    bool isValidParentheses(string& s, int i, int j){
        int open = 0;
        for(int k=i;k<=j;k++){
            if(s[k]=='('){
                open++;
            }else{
                if(open==0) return false;
                open--;
            }
        }

        return open == 0;
    }
    int longestValidParentheses(string s) {
        int n = s.size();
        
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                }else{
                    st.push(i);
                }
            }
        }

        //now stack only contain indices with no matching brackets
        //this also means string between any two adjacent unpaired brackets is a valid paranthese.
        if(st.empty()){
            //all matched
            return n;
        }
        int ans = 0;
        int a = n, b=0;
        while(!st.empty()){
            b = st.top();st.pop();
            
            ans = max(ans, a-b-1);

            a= b;
        }
        ans = max(ans, a);
        return ans;
    }
};