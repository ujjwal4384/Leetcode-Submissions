auto comp=[](vector<int>&v1, vector<int>&v2){
    if(v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(), intervals.end(), comp);
        int n=intervals.size();
        int l=intervals[0][0], r = intervals[0][1];
        for(int i=1;i<n;i++){
               vector<int>interval = intervals[i];
               int st = interval[0], en= interval[1];
               if(st <=r){
                  r = max(r,en);
               }
               else{
                  res.push_back({l, r});
                  l=st, r = en;
               }
        }
        res.push_back({l,r});

      return res;  
    } 
};