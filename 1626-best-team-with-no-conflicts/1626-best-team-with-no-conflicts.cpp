class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        //{age, score} pe sort karo -> 
        //LIS: Longwst increasing subsequence DP variation ->Maximum Sum Increasing Subsequence
        // dp[i] represents the maximum possible score of a valid team where players[i] is strictly the LAST player added.
        //Because we sorted the players by age beforehand, being the "last player added" means players[i] is the oldest player on that specific team combination.
        int n = scores.size();
        vector<pair<int,int>>vp(n);
        for(int i=0;i<n;i++){
           vp[i] = make_pair(ages[i], scores[i]); 
        }
        sort(vp.begin(), vp.end());
        vector<int>dp(n);
        
        for(int i=0;i<n;i++){
            dp[i] = vp[i].second;
            for(int j=0; j<i ; j++){
                   if(vp[i].second >= vp[j].second){
                      dp[i] = max(dp[i], dp[j] + vp[i].second); 
                   } 
            }
        }    
       return (*max_element(dp.begin(), dp.end()));  
    }
};