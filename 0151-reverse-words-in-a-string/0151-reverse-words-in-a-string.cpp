class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        int n = s.size();
        int i=0;
        while(i<n){
             while(s[i] == ' ') i++;
             string word;
             while(i<n && s[i] != ' ')word += s[i++] ;
             if(word.size())words.push_back(word);
        }
        string ans;
        reverse(words.begin(), words.end());
        for(auto word: words){
            ans += word + " ";        
        }
        ans.pop_back();
        return ans;

    }
};