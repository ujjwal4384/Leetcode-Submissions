class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prevRow = nums; 
        for(int i = 1; i<n; i++){
             int sz = prevRow.size();
             
             vector<int>newRow(sz-1, 0);
             for(int j=0; j<sz-1; j++){
                 newRow[j] = (prevRow[j] + prevRow[j+1])%10 ;
             }
             prevRow = newRow;
        }
        return prevRow.front();
    }
};