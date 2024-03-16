class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>prev(n,0);
        
        for(int row=0;row<n;row++){
            vector<int>cur(n);
            for(int col=0;col<n;col++){
                int a=INT_MAX,b=INT_MAX,c=INT_MAX;
                if(col-1>=0)a= prev[col-1];
                if(col+1<n)c= prev[col+1];
                b=prev[col];
               
                cur[col] = min(a,min(b,c))+ matrix[row][col]; 
            }
            prev= cur;
        }
     return *min_element(prev.begin(), prev.end());   
    }
};