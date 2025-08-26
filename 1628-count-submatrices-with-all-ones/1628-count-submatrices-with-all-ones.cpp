class Solution {
public:
    int oneDArraySubmatricesCount(vector<int>&v){
        int n = v.size();
        int cnt =0;
        int add = 0;
        for(int i=0;i<n;i++){
            
            if(v[i]==1){
                add++;    
            }else{
                add = 0;
            }
            cnt += add;
        }
        return cnt;
    }

    int numSubmat(vector<vector<int>>& mat) {
           int m =mat.size(), n=mat[0].size();
           int count = 0;
           for(int startRow=0;startRow<m;startRow++){
             vector<int>temp(n,1);
             for(int endRow=startRow;endRow<m;endRow++){
                    for(int j=0;j<n;j++){
                        temp[j] = temp[j] & mat[endRow][j];
                    }
                    count += oneDArraySubmatricesCount(temp);
             }
           }
      return count;     
    }
};