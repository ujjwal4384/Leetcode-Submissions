class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>v = nums;
        v.insert(v.end(), nums.begin(), nums.end());
        
        
        
        vector<int>nge(n, -1);
        stack<int>st;
        for(int j=v.size() -1;j>=0;j--){
               while(!st.empty() && v[j] >= v[st.top()]) st.pop();
               if(j<=n-1){
                if(st.empty())nge[j] = -1;
                else nge[j] = v[st.top()];
               }
               st.push(j);
        }
        
        return nge;
    }
};