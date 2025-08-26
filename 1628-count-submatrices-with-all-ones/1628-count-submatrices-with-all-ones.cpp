class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        vector<int>h(n,0);  //histogram
        int ans = 0;
        for(int row=0;row<m;row++){
            // find all rectangles ending at this row.
            //    = sum of count all rect. ending at each col of this row.
            // where count of rectangles ending at col[j] of this row = area of largest rectangle made with this height from 0th col to jth col.
            for(int col=0;col<n;col++){
                h[col] = mat[row][col] ? h[col] + 1 : 0;
            }
            vector<int>pre(n,-1);
            stack<int>st;
            for(int col=0;col<n;col++){
                while(!st.empty() && h[st.top()]>=h[col])st.pop();
                if(st.empty())pre[col] = -1;
                else pre[col] = st.top();
                st.push(col);
            }

            vector<int> sum(n, 0);
            int totSum = 0;
            for(int col=0;col<n;col++){
                sum[col] +=  h[col]*(col - pre[col]) ;
                if(pre[col] !=-1){
                    sum[col]+= sum[pre[col]];
                }
                totSum += sum[col];
            }
            ans += totSum;
             
        }

        return ans;
    }
};