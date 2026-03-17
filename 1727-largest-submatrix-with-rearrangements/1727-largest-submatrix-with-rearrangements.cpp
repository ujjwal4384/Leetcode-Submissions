class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n= matrix[0].size();
        int maxi =0;
        for(int i=0;i<m;i++){
                
            for(int j=0;j<n;j++){        
                if(matrix[i][j] ==1 && i>0){
                       matrix[i][j] += matrix[i-1][j]; 
                }  
            }
            vector<int>his = matrix[i];
            sort(his.begin(), his.end(), greater<int>());
             
            for(int k=0;k<n;k++){
                int area = his[k] * (k+1);
                maxi = max(maxi, area);
            }
        }
        return maxi;
    }
};