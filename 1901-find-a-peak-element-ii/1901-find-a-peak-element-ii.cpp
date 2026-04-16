class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size() ;
        int l_col = 0, r_col = n-1;
        vector<int>ans(2, -1);
        while(l_col<=r_col){
                int m_col = l_col +  (r_col-l_col>>1) ;
                int max_row = 0;
                for(int row =1; row<m; row++){
                     if(mat[row][m_col] > mat[max_row][m_col]){
                        max_row = row;
                     }
                }
                bool isBiggerFromLeft = m_col-1 >=0 ? mat[max_row][m_col] > mat[max_row][m_col-1] : 1;
                bool isBiggerFromRight = m_col+1 < n ? mat[max_row][m_col] > mat[max_row][m_col+1] : 1;
                if(isBiggerFromLeft && isBiggerFromRight) return {max_row, m_col};
                if(!isBiggerFromLeft){
                    //means left side is bigger
                    r_col = m_col -1 ;
                }else{
                    l_col = m_col + 1;
                }
        }
        return ans;  
    }
};