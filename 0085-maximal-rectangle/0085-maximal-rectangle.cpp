class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
            int cur = heights[i] *(r-l+1);
            ans=max(ans, cur);
        }
        return ans;
    } 
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxi=0;
        vector<int>prev(n, 0), cur(n,0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n; j++){
                if(matrix[i][j]=='1'){
                    cur[j] = prev[j] + 1;
                }else{
                    cur[j] = 0;
                }    
            }
            int area = largestRectangleArea(cur);
            maxi= max(maxi, area);
            prev= cur;
        }

        return maxi;
    }
};