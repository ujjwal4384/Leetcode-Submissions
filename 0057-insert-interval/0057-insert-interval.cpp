class Solution {
    static bool sortFunc(vector<int>&v1, vector<int>&v2){
        if(v1[0]==v2[0]){
            return v1[1]<v2[1];
        }
        return v1[0] < v2[0];
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), sortFunc);
        vector<vector<int>>res;

        int l = intervals[0][0], r= intervals[0][1];
        for(int i=0;i<intervals.size() -1; i++){
            if(intervals[i+1][0] <= r){
                r= max(r, intervals[i+1][1]);
            }else{
                res.push_back({l, r});
                l = intervals[i+1][0],r=intervals[i+1][1];
            } 
        }

        res.push_back({l, r});

        return res;
    }
};