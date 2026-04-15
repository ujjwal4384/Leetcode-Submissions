class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        int i=0, j = n-1; //BST matrix[0][n-1] is root node left : are smaller, right are larger
        while(i<m && j>=0){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] > target){
                    j--;
            }else{
                    i++;  
            }
        }
        return false;
    }
};