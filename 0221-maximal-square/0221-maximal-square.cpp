class Solution {
    vector<vector<int>>pre;
    int m,n;
public:
    bool findSquare(int side, vector<vector<char>>& matrix){
        int countNeed = side*side;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                int i1=i-side+1,j1=j-side+1; 
                if(i1>=0 && j1>=0 && i1<m&& j1<n){
                int countOnes = pre[i][j] - (j1-1>=0?pre[i][j1-1]:0) -  (i1-1>=0?pre[i1-1][j]:0) +  (i1-1>=0&&j1-1>=0?pre[i1-1][j1-1]:0); 
                 if(countOnes==countNeed) return true;   
                }
            }
        }
       return false; 
    }
   
    void getPrefixSumMatrix(vector<vector<char>>& matrix){
        pre[0][0]= matrix[0][0]-'0';
        for(int j=1;j<n;j++){
            pre[0][j]= pre[0][j-1] + (matrix[0][j]-'0');
        }
        for(int i=1;i<m;i++){
            pre[i][0] = pre[i-1][0] + (matrix[i][0]-'0');
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                pre[i][j] = (pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1]) + (matrix[i][j]-'0');
            }
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m= matrix.size(),n=matrix[0].size();
        pre.clear();
        pre= vector<vector<int>>(m, vector<int>(n,0));
        // make 2d prefix sum matrix
        getPrefixSumMatrix(matrix);
        
        //apply binarySearch
        int l= 1, h= max(1, min(m,n));
        int ans=0;
        while(l<=h){
            int side= (l+h)/2;
            cout<<"attempt: side"<<side<<endl;
            if(findSquare(side, matrix)){
                ans=side;
                l= side+1;
            }else{
                h=side-1;
            }
        }
        return ans*ans;
    }
};