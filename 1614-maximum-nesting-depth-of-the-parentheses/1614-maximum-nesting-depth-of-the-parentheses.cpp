class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int open = 0;
        int ans = 0;
        for(auto ch:s){
            if(ch=='(')open++;
            else if(ch == ')')open--;
            ans = max(ans, open);
        }
        return ans;
    }
};