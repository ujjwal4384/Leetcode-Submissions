class Solution {
public:
    int characterReplacement(string s, int k) {
     int n = s.size();
     int global_max = 0;

     for(char ch='A';ch<='Z';ch++){    
        
        int l=0,r=0;
        int maxi = 0;
        int balance = k;
        
        while(r<n){
                if(s[r]!=ch)balance--;
                while(balance <0 ){
                    if(s[l]!=ch)balance++;
                    l++;
                }
                maxi = max(maxi, r-l+1);
                r++;
        }

        global_max = max(global_max, maxi);

     }


     return global_max;
    }
};