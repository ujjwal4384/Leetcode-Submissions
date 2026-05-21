class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1) return n;
        int ans = 1;
        int freq[256] = {0};
        int l=0, r=0;
        while(r<n){
            freq[s[r]]++;
            while(freq[s[r]] > 1){
                    freq[s[l]]--;
                    l++; 
            }
            ans = max(ans, r-l+1);
            r++;
        }
     return ans;   
    }
};