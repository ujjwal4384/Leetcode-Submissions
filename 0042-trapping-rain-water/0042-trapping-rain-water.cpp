class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
         int l=0, r= n-1;
         int maxL= 0, maxR = 0;
         int water = 0;
         while(l<r){
                if(height[l] < height[r]){
                    //left is bottlenexk for trapping water for this i height
                    maxL = max(maxL, height[l]);
                    water += maxL - height[l] ;
                    l++;
                }else{
                    maxR = max(maxR, height[r]);
                    water += maxR - height[r] ;
                    r--;
                }
         }
         
         return water;
    }
};