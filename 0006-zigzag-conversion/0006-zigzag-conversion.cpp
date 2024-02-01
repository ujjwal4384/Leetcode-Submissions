class Solution {
public:
    string convert(string s, int numRows) {
       
        int n=s.size();
         if(numRows==1) return s;
        vector<vector<char>>v(n, vector<char>(n,' '));
        int i=0,j=0, pos=0;
        bool down=true;
        while(pos<n){
            char ch = s[pos];
            
            v[i][j] = ch;
           if(down){
                  if(i<numRows-1){
                      i++;
                  }
                  else if(i==numRows-1){
                      down=false,i--,j++;
                  }
           }else{
               if(i>0){
                   i--,j++;
                }
               else if(i==0){
                   down=true,i++;
               }
               
           } 
            pos++;
        }
        string res="";
        for(auto&x:v){
            for(auto&y:x){
               if(y!=' ')res+=y;
            }
        }
        return res;
    }
};