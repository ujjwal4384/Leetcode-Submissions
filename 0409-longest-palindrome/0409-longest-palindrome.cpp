class Solution {
public:
    int longestPalindrome(string s) {
         map<int,int>freq;
        int n=s.size();
        for(auto&ch:s)freq[ch]++;

        int ans =0;
        bool isOdd=false;
        for(auto&p:freq){
             if(p.second%2){
                 isOdd=true;
                 ans+= (p.second-1);
             }else{
                 ans+=p.second;
             }
        }
     return isOdd? ans+1 : ans;
    }
};