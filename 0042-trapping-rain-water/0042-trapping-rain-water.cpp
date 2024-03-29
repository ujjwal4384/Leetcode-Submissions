class Solution {
public:
    int trap(vector<int>& height) {
      
        int n=height.size();
        //pre[i]= stores max height from 0->i-1.
        //suff[i]= stores max height from n-1 to i+1.
        vector<int>suff(n,0);
       
        for(int i=n-2;i>=0;i--){
            suff[i] = max(suff[i+1], height[i+1]);
        }
        int tot=0;
        int pre=0;
        for(int i=1;i<=n-2;i++){
            pre = max(pre, height[i-1]);
            int h = min( pre, suff[i]);
            if(h>height[i]){
               int cur = (h - height[i]); 
                tot+=cur;
            }
        }
        return tot;
    }
};