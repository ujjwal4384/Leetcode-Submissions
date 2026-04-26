
struct Job{
 int st;
 int en;
 int profit;
 Job(int s, int e, int p){
     st=s,en=e, profit =p;
 }
};


class Solution {
    static bool compare(const Job& a, const Job& b) {
        return a.st < b.st;
    }
public:
    int solve(int i, vector<Job>&jobs, vector<int>&dp){
       if(i>= jobs.size()) return 0;
       if(dp[i] != -1) return dp[i];
       int notTake = 0;
       int take =  0;
       notTake = 0 + solve(i+1, jobs, dp);
       take = jobs[i].profit;
       int j = lower_bound(jobs.begin(), jobs.end(), Job(jobs[i].en, 0, 0), compare) - jobs.begin();
       if(j < jobs.size()){
            take += solve(j, jobs, dp); 
       }
       return dp[i] = max(notTake, take) ; 
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         
         vector<Job>jobs;
         int n = startTime.size();
         vector<int>dp(n, -1);
         for(int i=0;i<n; i++){
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
         }
         sort(jobs.begin(), jobs.end(), compare);
         int ans = solve(0, jobs, dp);
         return ans;
    }
};