class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex <0) return {};

        vector<int>prevRow = {1}; 
        for(int i = 1; i<=rowIndex; i++){
             int sz = prevRow.size();
             
             vector<int>newRow(sz+1, 1);
             for(int j=1; j<sz; j++){
                 newRow[j] = (prevRow[j] + prevRow[j-1]);
             }
             prevRow = newRow;
        }
        return prevRow;
    }
};