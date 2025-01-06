class Solution {
public:
    static bool comp(vector<int>&v1, vector<int>&v2){
        if(v1[1]==v2[1]) return v1[0]>v2[0];
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);

        int ans =0;
        for(auto&v: boxTypes){
            int boxes = v[0];
            int units = v[1];
            
            int take = min(boxes, truckSize);
            truckSize -= take;
            ans += units * take;
            
        }

        return ans;
    }
};