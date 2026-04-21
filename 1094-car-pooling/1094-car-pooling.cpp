class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diff(10001, 0);
        for(auto& trip:trips){
                 int l = trip[1], r= trip[2], val = trip[0];
                 diff[l] += val;
                 diff[r] -= val;
        }

        for(int i=0;i<=1000; i++){
            if(i>0) diff[i] += diff[i-1];
            if(diff[i] > capacity) return false;
        }
        return true;
    }
};