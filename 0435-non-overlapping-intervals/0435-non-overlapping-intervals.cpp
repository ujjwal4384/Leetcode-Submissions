class Solution {
    static bool sortFunc(vector<int>&v1, vector<int>&v2){
        if(v1[0]==v2[0]){
            return v1[1]<v2[1];
        }
        return v1[0] < v2[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), sortFunc);
        
        int ans =0;
        
        int  r= intervals[0][1];
        
        for(int i=1;i<intervals.size(); i++){
            if(intervals[i][0] < r){
                r= min(r, intervals[i][1]);
                ans++;
            } 
            else {
                r= intervals[i][1];
            }
        }
        
        return ans;
    }
};