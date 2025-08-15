class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
       
        int l=0,r=n-1,lMax =0,rMax=0, ans =0;
        
        while(l<r){
            int hl = height[l], hr= height[r];
            if(hl <= hr){
                ans += max(0, lMax-hl);
                lMax = max(lMax, hl);
                l++;
            }else{
                ans += max(0, rMax-hr);
                rMax = max(rMax, hr);
                r--;
            }
        }
        return ans;
    }
};
