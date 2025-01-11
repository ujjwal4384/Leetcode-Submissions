class Solution {
    static bool sortFunc(vector<int>&v1,vector<int>&v2 ){
        if(v1[0] == v2[0]){
            return v1[1] < v2[1];
        }
        return v1[0] < v2[0];
    }
public:
     
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<=1) return n;
        sort(intervals.begin(), intervals.end(), sortFunc);

        int remove = 0;
        int  st=-1, en = -1;  
        for(int i=0;i<n;i++){
             int l = intervals[i][0], r = intervals[i][1];
             
             if(l>r || r <=en){
                //remove this interval
                 remove++;
             }   
             else {
                if(l==st)remove++;
                st = max(st, l);
                en = max(en, r);
             }
        }

        return n-remove;
    }
};