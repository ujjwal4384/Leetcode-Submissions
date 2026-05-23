class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     int n = matrix.size();
     //solving in layers, 4 way swap
     //mirrorImage[j][n-1-i] = matrix[i][j]
     /*
        old_row = i old_col = j
        new_row=j   new_col = n-1-j appl;y this four times to get top right bottom right bottom left coordinates
     */

     /*
     i defines layers. 
     and j traverses the top row of that layer
      becasue on every top-left element: it's corresponding top-right, bottom-right and bottom-left are also getting placed correctly.
     */
     for(int i= 0; i<n/2; i++){
        for(int j=i;j< n-1-i; j++){
             int top_left = matrix[i][j];
             int top_right = matrix[j][n-1-i] ;//top-right
             int bottom_right = matrix[n-1-i][n-1-j]; //bottom-right
             int bottom_left = matrix[n-1-j][i]; //bottom-left
             
             
             matrix[j][n-1-i] = top_left;
             matrix[n-1-i][n-1-j] = top_right;
             matrix[n-1-j][i] = bottom_right;
             matrix[i][j] = bottom_left;
        }
     }
    }
};