class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        v.push_back({1});
        for(int row = 2; row<=numRows; row++){
             int sz = v.back().size();
             vector<int>lastRow = v.back();
             vector<int>newRow(sz+1, 1);
             for(int j=1; j<sz; j++){
                 newRow[j] = (lastRow[j] + lastRow[j-1]);
             }
             
             v.push_back(newRow);
        }
        return v;
    }
};