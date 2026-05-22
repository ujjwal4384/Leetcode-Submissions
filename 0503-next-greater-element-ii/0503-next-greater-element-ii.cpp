class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n = v.size();
        // vector<int>v = nums;
        // v.insert(v.end(), nums.begin(), nums.end());
        
        
        
        vector<int>nge(n, -1);
        stack<int>st;
        for(int j=2*n -1;j>=0;j--){
               while(!st.empty() && v[j%n] >= v[st.top()]) st.pop();
               if(j<=n-1){
                if(st.empty())nge[j] = -1;
                else nge[j] = v[st.top()];
               }
               st.push(j%n);
        }
        
        return nge;
    }
};