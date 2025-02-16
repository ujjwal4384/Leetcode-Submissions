class Solution {
public:
    int largestRectangleArea(vector<int>& heights, int k) {
        stack<int>st;
        int n= heights.size();
        vector<int>pre(n,0),suff(n,0);
        pre[0] = -1;
        suff[n-1] = -1;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();

            }
            if(st.empty()){
                pre[i] = -1;
            }
            else{
                pre[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty())st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();

            }
            if(st.empty()){
                suff[i] = n;
            }
            else{
                suff[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
          for(int i=0;i<n;i++){
            int l = pre[i]+1;
            int r = suff[i]-1;
            if(l<=k && k<=r){
                int cur = heights[i] *(r-l+1);
                ans=max(ans, cur);
            }
            
        }
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
        return largestRectangleArea(nums, k);
    }
};