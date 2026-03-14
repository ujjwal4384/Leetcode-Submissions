class Solution {
    int n;
    int dp[41][1024];
    unordered_map<int,vector<int>>hatToPerson;
    int MOD = 1e9+7;

public:
    int solve(int hat, int mask){
        if(mask ==  ((1<<n) -1)) return 1;
        if(hat > 40) return 0;
        if(dp[hat][mask] !=-1) return dp[hat][mask];
        int ways = solve(hat+1, mask); //nobody wears this hat is skipped.
        for(auto person: hatToPerson[hat]){
            bool canPutHatInThisPerson = (mask & (1<<person)) == 0;
            if(canPutHatInThisPerson){
                //actually put this hat
                 ways = (0LL +  ways + solve(hat+1, mask | (1<<person)) + MOD)%MOD;
            }   
        }

       return dp[hat][mask] = ways; 
    }

    int numberWays(vector<vector<int>>& hats) {
      
         n= hats.size();
         memset(dp, -1, sizeof(dp));
         hatToPerson.clear();
         for(int i=0;i<n; i++){
            for(int j=0;j<hats[i].size(); j++){
                 hatToPerson[hats[i][j]].push_back(i);
            }
         }
         return solve(1, 0);
    }
};