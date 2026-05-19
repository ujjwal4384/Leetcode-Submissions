class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // vector<int>diff(10001, 0);
        map<int,int>diff;
        for(auto& trip:trips){
                 int l = trip[1], r= trip[2], val = trip[0];
                 diff[l] += val;
                 diff[r] -= val;
        }
        int curCap = 0;
        for(auto& p:diff){
            curCap += p.second; 
            if(curCap > capacity) return false;
        }
        return true;
    }
};