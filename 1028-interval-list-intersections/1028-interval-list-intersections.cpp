class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        vector<vector<int>>res;
        int n1= v1.size(), n2 = v2.size();

        int i=0,j=0;
        while(i<n1 && j<n2){
           
            int l1 = v1[i][0], r1=v1[i][1], l2=v2[j][0], r2=v2[j][1];
            
            int st = max(l1, l2), en = min(r1, r2);
            if(st<=en){
                res.push_back({st, en});
            }
            if(en == r1) i++;
            else j++;
           
        }

        return res;
    }
};