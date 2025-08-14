class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pre(n,0),suff(n,0);

        for(int i=0; i<n; i++){
            pre[i]= height[i];
            if(i>0){
                pre[i] = max(height[i], pre[i-1]);
            }
        }

        for(int j=n-1;j>=0;j--){
            suff[j] = height[j];
            if(j<n-1){            
                suff[j] = max(height[j], suff[j+1]);
            }
        }

        int ans =0;
        for(int i=1;i<n-1;i++){
            int h = height[i];
            int h2 = min(pre[i-1], suff[i+1]);
            int water = max(0, h2 - h);
            ans += water;
        }
        return ans;
    }
};
