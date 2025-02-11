class Solution {
public:
    bool isValid(map<char, int>&mp, map<char, int>&freq){
        for(auto p : freq){
            char x = p.first;
            int count = p.second;
            if(mp[x] < count) return false;
        }
       return true; 
    }

    string minWindow(string s, string t) {
        map<char, int>freq, mp;
        for(auto&x:t)freq[x]++;

        int m = s.size(), n= t.size();
        
        int len = m+n+1;
        int start = -1;
        
        for(int st=0,en=0; en<m; en++){
            
            mp[s[en]] ++ ;
            
            if(isValid(mp, freq)){
                
                while(st<=en){
                    int need = freq[s[st]];
                    int cur = mp[s[st]];
                    if(cur - need > 0){
                        mp[s[st]]--;
                        st++;
                    }else{
                        break;
                    }
                }
                
                int curLen = en - st + 1;
                if(curLen < len){
                    len = curLen;
                    start = st;
                }

               
            }
        }

        return len==m+n+1 ? "" : s.substr(start, len);
    }
};