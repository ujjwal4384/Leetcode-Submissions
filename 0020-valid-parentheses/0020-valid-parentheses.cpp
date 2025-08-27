class Solution {
public:
    char open[3] = {'(', '{', '['};
    char close[3] = {')', '}', ']'}; 

    bool isOpen(char ch){
        for(auto br:open){
                if(br==ch)return true;
        }
        return false;    
    }

    bool isValid(string s) {
        stack<char>st;
        
        for(auto ch:s){
            if(isOpen(ch)){
                st.push(ch);
            }else{
                if(st.empty()) return false;
                char top = st.top();
                bool isVal =false;
                if(ch==')' && top =='(') isVal= true;
                if(ch=='}' && top =='{') isVal= true;
                if(ch==']' && top =='[') isVal= true;
                if(!isVal) return false;
                st.pop();
            }
        }

        return st.empty();
    }
};