class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();

        //edge cases
        if(m < n) return "";


        int requiredChar[256]={0};
        int countOfRequiredChars = 0;
        for(auto&ch:t){
            requiredChar[ch]++;
            countOfRequiredChars++;
        }


        int ans_st = -1, ans_len = INT_MAX;
        int l=0;
        //sliding_window
        for(int r=0;r<m;r++){
            //STEP-1: EXPANSION
             char ch = s[r];
             if(requiredChar[ch] > 0){
                countOfRequiredChars--;    
             }
             requiredChar[ch]--;
             
             //STEP-2: CHECK VALIDITY
             while(countOfRequiredChars == 0){
                //STEP 3: IF_VALID-> SHRINK
                int cur_st = l, cur_len = r-l+1;
                if(cur_len < ans_len){
                    ans_st = cur_st, ans_len = cur_len;
                }
                requiredChar[s[l]]++;
                if(requiredChar[s[l]] > 0)countOfRequiredChars++;
                l++;
             }
        }
        return ans_st == -1 ? "" : s.substr(ans_st, ans_len);
    }
};