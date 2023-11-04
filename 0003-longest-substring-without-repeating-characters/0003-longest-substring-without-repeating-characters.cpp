class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window of dynamic size
        int n=s.size();
        if(n<=1) return n; 
        int st =0, en =1;
        map<char, int>mp;
        mp[s[0]]=1;
        int maxi =1;
        while(en<n){
            //  cout<<st<<" "<<en<<"    #  mp[s[en]] = "<<mp[s[en]]<<endl;
             
         if(!mp[s[en]]){
             mp[s[en]] = 1;
             maxi = max(maxi, en-st +1);
             en++;
         }else{
             while(s[st] !=s[en]){
                 mp[s[st]] =0;
                 st++;
             }
             st++;
             en++;
         }
         
        }
       return maxi; 
    }
};