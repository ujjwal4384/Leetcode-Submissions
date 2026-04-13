class Solution {
  
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int m = matrix.size(), n=matrix[0].size() ;
         //BST with top right corner as root. ledft: all smaller, down: all greater
         //at every step eliminate one row/col. O(m+n)
         int r = 0, c = n-1;
         while(r<m && c>=0){
                if(matrix[r][c] == target) return true;
                else if(matrix[r][c] < target){
                    //eliminate the row. target can't lie in that row.
                    r++;
                }else c--;
         }
         return false;
    }
};