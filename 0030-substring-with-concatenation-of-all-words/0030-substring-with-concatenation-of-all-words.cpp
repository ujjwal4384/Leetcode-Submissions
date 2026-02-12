class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = s.size();
        int numWords = words.size();
        int wordLen = words[0].size();
        vector<int>ans;
        unordered_map<string,int>freqMap;
        for(auto word:words)freqMap[word]++;

        for(int i=0;i<wordLen;i++){
                unordered_map<string,int>requiredCount = freqMap;
                int wordsToMatch = numWords;
                int l =i, r = i;
                while(r+wordLen-1 < m){
                    string word = s.substr(r, wordLen);
                    if(requiredCount.count(word) && requiredCount[word] >0){
                       wordsToMatch--; 
                    }
                    requiredCount[word]--;
                    int windowSize = r-l+ wordLen;

                    //shrink
                    if(windowSize == numWords*wordLen){
                        if(wordsToMatch == 0)ans.push_back(l);
                        string wordToRem = s.substr(l,wordLen);
                        requiredCount[wordToRem]++;
                        if(requiredCount.count(wordToRem) &&requiredCount[wordToRem] > 0) wordsToMatch++;
                        l += wordLen;
                    }
                    r += wordLen;    
                }
        }
      return ans;  
    }
};