class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
         vector<int>leftMax(n);
         vector<int>rightMax(n);
         for(int i=0;i<n;i++){
            leftMax[i] = i-1 >=0 ? max(height[i], leftMax[i-1]) : height[i];
         }

         for(int i=n-1;i>=0;i--){
            rightMax[i] = i+1<n ? max(rightMax[i+1], height[i]) : height[i];
         }

         int water = 0; 
         for(int i=0;i<n;i++){
            water +=  min(leftMax[i], rightMax[i]) - height[i];
         }
         return water;
    }
};