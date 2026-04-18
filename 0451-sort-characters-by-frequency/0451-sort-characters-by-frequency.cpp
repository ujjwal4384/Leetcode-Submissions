class Solution {
public:
    string frequencySort(string s) {
        
        vector<int>charToFreq(126, 0);
        
        int n = s.size();
        for(auto c:s)charToFreq[c]++;

        map<int, vector<int>, greater<int>>freqToChar;
        for(int i=0;i<126; i++){
            int count = charToFreq[i];
            if(count>0)freqToChar[count].push_back(i);
        }
        string ans = "";
        for(auto p: freqToChar){
            int count = p.first;
               for(auto x:p.second){
                   char ch = x;
                   string str(count, ch);
                   ans += str;
               }
        }

        return ans;         
    }
};