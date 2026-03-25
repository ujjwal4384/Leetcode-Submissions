class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        vector<long long>row(m, 0), col(n, 0);
        long long sum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum += grid[i][j];
                row[i] += grid[i][j];
            }
        }

        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                col[j] += grid[i][j];
            }
        }

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