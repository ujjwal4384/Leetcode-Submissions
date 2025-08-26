class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int>pre(n,-1),suff(n,n);
        stack<int>st;
        for(int i = 0; i<n;i++){
               while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
               if(st.empty())pre[i] = -1;
               else pre[i] = st.top();
               st.push(i);
        }
        while(!st.empty())st.pop();

        for(int i = n-1; i>=0;i--){
               while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
               if(st.empty())suff[i] = n;
               else suff[i] = st.top();
               st.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, (suff[i] - pre[i] -1)*heights[i]);
        }
        return ans;
    }
};