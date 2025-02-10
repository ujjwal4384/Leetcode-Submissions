class Solution {
public:
    vector<int> nextGreaterEl(vector<int>& height){
        int n= height.size();
        vector<int>v(n, -1);
        stack<int>st;
        for(int i=n-1;i>=0; i--){
            while(!st.empty() && height[st.top()] <= height[i])st.pop();
            
            v[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return v;
    }
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int l=0, r= n-1, maxi = 0;
       
       while(l<r){
            if(height[l]<=height[r]){
                int cur = height[l] * (r-l);
                maxi = max(maxi, cur);
                l++;
            }else{
                int cur = height[r] * (r-l);
                maxi = max(maxi, cur);
                r--;
            }
       }
        return maxi;
    }
};