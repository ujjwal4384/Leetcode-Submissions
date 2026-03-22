class Solution {
public:
    void rotate(vector<vector<int>>&mat){
        //rotate by 90 degree -> take transpose then reverse rows.
        int n= mat.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(mat[i].begin(), mat[i].end());
        }

    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

            for(int i=0;i<4;i++){
                rotate(mat);
                if(mat==target) return true;
            }      
            return false;
    }
};