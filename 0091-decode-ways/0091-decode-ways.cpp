class Solution {
    vector<int>dp;
public:
    int f(int i, string&s){
        if(i == s.size()) return 1;
        if(dp[i]!=-1)return dp[i];
        int tot = 0;
        string t = "";
        for(int j=i;j<s.size(); j++){
            t += s[j];
            bool condA = t.size() == 1 && t[0]!='0';
            bool condB = t.size() ==2 && (t>="10" && t<="26");
            if(condA || condB){
                tot += f(j+1, s);
            }
        }
        return dp[i] = tot;
    }

    int numDecodings(string s) {
        dp.assign(s.size(), -1);
        return f(0, s);
    }
};