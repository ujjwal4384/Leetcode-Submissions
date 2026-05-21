class Solution {
private:
    bool isValid(map<char,int>&freqT, map<char,int>&freqWindow){
        for(auto p:freqT){
            if(freqWindow[p.first] < p.second) return false;
        }
      return true;
    }

public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n= t.size();
        string ans = "";
        if(m<n) return ans;

        vector<int>requiredCount(123, 0); //a-z->97-122.  A-Z: 65-90
        for(auto& x:t)requiredCount[x]++;
        int l=0,r=0;

        int charsToMatch= n;
        int ansStart = -1, ansLen = INT_MAX;
        int curLen = -1;
        
        while(r<m){
                int ch = s[r];
                if(requiredCount[ch] > 0){
                    charsToMatch --;
                }
                requiredCount[ch] --;//not required chacters will go negative.

                while(charsToMatch == 0 && l<=r){
                        if(r-l+1 < ansLen){
                            ansStart = l, ansLen = r-l+1;
                        }
                        char toRemoveChar = s[l];
                        requiredCount[toRemoveChar] ++;
                        if(requiredCount[toRemoveChar] > 0){ 
                             charsToMatch++;   
                        }
                        l++;
                }
                r++;
        }

       return ansStart == -1 ? "" : s.substr(ansStart, ansLen); 
    }
};