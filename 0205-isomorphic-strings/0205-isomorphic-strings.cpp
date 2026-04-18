
//bbbaaaba
//
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m) return false;
       //BIJECTION, need to check from both side to ensure 1:1 relationship
       vector<int>mapST(256, -1), mapTS(256, -1);
        for(int i=0;i<n;i++){
               int ch1 = s[i] , ch2 = t[i] ;
               if(mapST[ch1] != -1 && mapST[ch1] != ch2) return false;
               if(mapTS[ch2] != -1 && mapTS[ch2] != ch1) return false;
               mapST[ch1] = ch2;
               mapTS[ch2] = ch1;
        }

        
        return true;
        
    }
};