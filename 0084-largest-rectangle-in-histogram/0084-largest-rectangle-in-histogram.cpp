class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //max answer will have height = on of the height of the array
        //so for each array height, find max area possible with that height. 
        //then take max of all.
        
        //store prev/next smaller element: left, right.
        int n = heights.size();
        stack<int>st;
        vector<int>left(n,-1),right(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(!st.empty())left[i] = st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(!st.empty())right[i] = st.top();
            st.push(i);
        }
        int maxArea =0;
        for(int i=0;i<n;i++){
            int cur = heights[i]* (right[i]-left[i]-1);
            maxArea= max(cur, maxArea);
        }
        return maxArea;
    }
};