class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n= mat[0].size();
        k = k%n;
        for(int i=0;i<m;i++){
           
            for(int j=0;j<n;j++){
                 int new_index = (i%2==0) ? (j-k +n)%n : (j+k)%n ;
                if(mat[i][j] != mat[i][new_index]) return false;
            }
        }
        return true;
    }
};