class Solution {
public:
    int f(int i, int m, int n, vector<string>& strs, int dp[][101][101], int freq[]){
        if(i == strs.size()) return 0;
        if(m==0 && n==0) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        //2 ways : either include the string or exclude it.
        int way1=INT_MIN, way2=INT_MIN;
        
        //exclude
        way1= f(i+1, m, n, strs, dp, freq);
    
        
        //include 
        int availZero = m - freq[i];
        int availOne = n- (strs[i].size()-freq[i]); 
        if(availOne>=0 && availZero>=0){
            way2= 1 + f(i+1, availZero, availOne, strs, dp, freq);
        }
        return dp[i][m][n] = max(way1, way2);
    }
     int iterativeMethodfindMaxForm(vector<string>& strs, int M, int N) {
            //subset problem index aayga for sure as one of the state var
  //dp[i][m][n]= max subset size possible when starting from ith index with m zeroes and n ones available.
        int k=strs.size();
        int* freq = new int[k]{};
        for(int i=0;i<k;i++){
            string s=strs[i];
            int c=0;
            for(auto ch:s)c+=ch=='0';
            freq[i] = c;
        }
        int dp[601][101][101];
        // memset(dp, -1, sizeof(dp));
        
        // return f(0, m, n, strs, dp, freq);
        memset(dp, 0, sizeof(dp));
        for(int i=strs.size()-1;i>=0;i--){
            for(int m=0;m<=M;m++){
                for(int n=0;n<=N;n++){
                    int way1=INT_MIN, way2=INT_MIN;
                    //exclude
                    way1= dp[i+1][m][n];
                    //include 
                    int availZero = m - freq[i];
                    int availOne = n- (strs[i].size()-freq[i]); 
                    if(availOne>=0 && availZero>=0){
                        way2= 1 + dp[i+1][availZero][availOne];
                    }
                    dp[i][m][n] = max(way1, way2);
                }
            }
        }
      return dp[0][M][N];
    }
    int findMaxForm(vector<string>& strs, int M, int N) {
            //subset problem index aayga for sure as one of the state var
  //dp[i][m][n]= max subset size possible when starting from ith index with m zeroes and n ones available.
        int k=strs.size();
        int* freq = new int[k]{};
        for(int i=0;i<k;i++){
            string s=strs[i];
            int c=0;
            for(auto ch:s)c+=ch=='0';
            freq[i] = c;
        }
        int dp[101][101];
        // memset(dp, -1, sizeof(dp));
        
        // return f(0, m, n, strs, dp, freq);
        memset(dp, 0, sizeof(dp));
        for(int i=strs.size()-1;i>=0;i--){
            for(int m=M;m>=0;m--){
                for(int n=N;n>=0;n--){
                    int way1=INT_MIN, way2=INT_MIN;
                    //exclude
                    way1= dp[m][n];
                    //include 
                    int availZero = m - freq[i];
                    int availOne = n- (strs[i].size()-freq[i]); 
                    if(availOne>=0 && availZero>=0){
                        way2= 1 + dp[availZero][availOne];
                    }
                    dp[m][n] = max(way1, way2);
                    if(i==0)break;
                }
            }
        }
      return dp[M][N];
    }
};