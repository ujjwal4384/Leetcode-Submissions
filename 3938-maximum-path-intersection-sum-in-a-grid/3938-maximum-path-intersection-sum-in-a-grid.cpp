class Solution {
   int getMaxSumSubArray(vector<int>&nums){
       //KADANE ALGO FOR >=2 length subarrays
       int cur_sum = nums[0];
       int maxi = INT_MIN;
       for(int i=1; i<nums.size(); i++){
                   maxi = max(maxi, cur_sum + nums[i]) ;
                   cur_sum =max(nums[i], cur_sum +nums[i]);
       }
       
       return maxi;
   } 
public:
    int maxScore(vector<vector<int>>& grid) {
       //max subarray sum for every row, col.
       //edge case: except border element. it cannot be only border elemetn intersection.
        int m = grid.size(), n= grid[0].size();
        int maxi = INT_MIN;

        //check all strictly interior single cells
        for(int i=1;i<m-1; i++){
            for(int j=1;j<n-1;j++){
                maxi = max(maxi, grid[i][j]);
            }
        }

        //Now apply kadane for all rows, cols with condition >= 2 length subarrays
        for(int i=0;i<m;i++){
            int cur = getMaxSumSubArray(grid[i]);
            maxi = max(maxi, cur);
        }

        for(int j=0; j<n; j++){
            vector<int>v;
            for(int i=0;i<m;i++){
                v.push_back(grid[i][j]);
            }
            int cur = getMaxSumSubArray(v);
            maxi = max(maxi, cur);
        }
        return maxi;
    }
};