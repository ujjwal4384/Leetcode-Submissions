class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        vector<long long>row(m, 0), col(n, 0);
        long long sum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x = grid[i][j];
                sum += x;
                row[i] += x;
                col[j] += x;
            }
        }
        if(sum%2) return false;
        row.pop_back() ; 
        col.pop_back()  ;
        long long rowSum = 0;
        for(auto x:row){
            rowSum += x;
            if(rowSum*2 == sum)return true;
        }
        long long colSum = 0;
        for(auto x:col){
            colSum += x;
            if(colSum*2 == sum)return true;
        }
        
    return false;
    }
};