class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<int>ans;
        if(n>m) return ans;

        int charsNeedToMatch = n;
        vector<int>requiredCount(125, 0);
        for(auto& c:p)requiredCount[c]++;

        int l =0,  r =0;
        while(r<m){
            char ch = s[r];
            if(requiredCount[ch] > 0){
                charsNeedToMatch --;
            }
            requiredCount[ch] --;
            if(r-l+1 ==n){
                if(charsNeedToMatch == 0){
                    ans.push_back(l);
                }
                //remove previous old guy
                char toRem = s[l];
                requiredCount[toRem]++;
                if(requiredCount[toRem] > 0)charsNeedToMatch++;
                l++;
            }
            r++;
        }
        return ans;
    }
};