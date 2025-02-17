class Solution {
public:
    int f(int i, vector<string>& strs, int m, int n,map<int, int>&countZero,
        map<int, int>&countOne, int dp[601][101][101] ){
        if(m<0 || n<0) return -1e8;
        if(i==strs.size()){
            return 0;
        }
        
        else if(dp[i][m][n]!=-1) return dp[i][m][n];

        int take=INT_MIN, notTake=INT_MIN;
        
        if(m-countZero[i]>=0 && n-countOne[i]>=0){
            take =  1 + f(i+1, strs, m-countZero[i], n-countOne[i], countZero, countOne, dp);
        }
            notTake = 0 + f(i+1, strs, m, n, countZero, countOne, dp);
        
        
        return dp[i][m][n] = max(take, notTake);
    }    
    int findMaxForm(vector<string>& strs, int m, int n) {
        map<int, int>countZero;
        map<int, int>countOne;
        for(int i=0;i<strs.size(); i++){
            for(auto ch:strs[i]){
                if(ch=='0'){
                 countZero[i]++;
                }else{
                    countOne[i]++;
                }
            }
        }
        int dp[102][102];
         //memset(dp, -1, sizeof(dp));
        //return f(0, strs, m, n, countZero, countOne, dp);
        memset(dp, 0, sizeof(dp));
        for(int i=strs.size()-1 ; i>=0 ;i--){
            for(int z=m;z>=0;z--){
                for(int o=n;o>=0;o--){
                    
                    int take=INT_MIN, notTake=INT_MIN;
                    
                    if(z-countZero[i]>=0 && o-countOne[i]>=0){
                        take =  1 + dp[z-countZero[i]][o-countOne[i]];
                    }
                    
                    notTake = 0 + dp[z][o];
                    
                    
                    dp[z][o] = max(take, notTake);
                }
            }
        }

     
       return dp[m][n]; 
    }
};