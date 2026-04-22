class Solution {
    int MOD = 26;
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        int m = shifts.size();
        vector<int>dif(n, 0);
        for(const auto& v: shifts){
            int l = v[0], r = v[1], dir = v[2];
            int val = ( (dir==1) ? 1 : -1);
            dif[l]  = (dif[l] + val + MOD)%MOD;
            if(r+1< n) dif[r+1] = (dif[r+1] - val + MOD)%MOD;
        }
       
        for(int i=0;i<n;i++){
            if(i>0) dif[i] += dif[i-1];
            int shift = ( (s[i]- 'a') + dif[i] + MOD)%MOD;
            s[i] = 'a' + shift;
        }
        return s;
    }   
};