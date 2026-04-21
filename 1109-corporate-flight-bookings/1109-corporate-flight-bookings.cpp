class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        //difference array
       
        vector<int>diff(n, 0);
        for(auto booking: bookings){
                int l = booking[0] -1, r = booking[1] -1, val = booking[2];
                diff[l] += val;
                if(r+1<n) diff[r+1] -= val;
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = diff[i];
            if(i>0)ans[i] += ans[i-1];
        }
        return ans;
    }
};