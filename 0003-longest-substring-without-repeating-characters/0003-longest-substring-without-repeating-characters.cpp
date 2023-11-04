class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window of dynamic size

        int n=s.size();
        if(n<=1) return n; 

        int st =0, en =1;

        map<char, int>mp;
        //character currently getting iterated should have occurence to be 0 , if it's 1 that means it is already present in this window, so, forward the st pointer till you find that character, and also make occurences of all those forwared st chacters to 0 because now they are available to be taken in new window. 
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
             //do not make mp[en] =0 because it is part of updated window. 
             st++;
             en++;
         }
         
        }
       return maxi; 
    }
};
