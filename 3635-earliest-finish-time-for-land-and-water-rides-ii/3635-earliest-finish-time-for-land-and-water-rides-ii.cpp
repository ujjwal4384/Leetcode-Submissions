class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        // 1. Find the absolute earliest finish time for the FIRST ride
        int min_land_finish = INT_MAX;
        for(int i = 0; i < n; i++){
            min_land_finish = min(min_land_finish, landStartTime[i] + landDuration[i]);
        }
        
        int min_water_finish = INT_MAX;
        for(int i = 0; i < m; i++){
            min_water_finish = min(min_water_finish, waterStartTime[i] + waterDuration[i]);
        }
        
        int ans = INT_MAX;
        
        // Scenario 1: Earliest Land Ride -> Any Water Ride
        for(int i = 0; i < m; i++){
            // Start water ride when it opens, or when we arrive (whichever is later)
            int actual_start = max(min_land_finish, waterStartTime[i]);
            ans = min(ans, actual_start + waterDuration[i]);
        }
        
        // Scenario 2: Earliest Water Ride -> Any Land Ride
        for(int i = 0; i < n; i++){
            // Start land ride when it opens, or when we arrive (whichever is later)
            int actual_start = max(min_water_finish, landStartTime[i]);
            ans = min(ans, actual_start + landDuration[i]);
        }
        
        return ans;
    }
};