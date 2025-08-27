class Solution {
public:
    string simplifyPath(string path) {
        int n= path.size();
        int i=0;
        vector<string> res;
        string curFileName ="";
        while(i<path.size()){
            // get consecutive slashes count
            char ch = path[i];

            // case-1: slashes
            if(ch=='/'){
               while(i<n && path[i]=='/') i++;
               continue;
            }
            else if(ch=='.'){
                
                int cnt = 0;
                while(i<n && path[i]=='.') i++, cnt++;  
                
                
                if(cnt==1){
                     if(i==n || path[i]=='/'){
                        continue;
                     }else{
                        curFileName=string(cnt,'.');
                     } 
                     continue;
                }else if(cnt ==2){
                    if(i==n || path[i]=='/'){  
                     if(res.size())
                       res.pop_back();
                    }
                    else curFileName=string(cnt,'.');
                    continue;  
                }else{
                    curFileName=string(cnt,'.');
                    
                    if(i==n || path[i]=='/'){
                        res.push_back(curFileName);
                        curFileName = ""; 
                    }
                    continue;
                }
            }else{
                // get until you reach slash
               
                while(i<n && path[i] !='/')curFileName += path[i], i++;
                res.push_back(curFileName);
                curFileName = "";
                continue;
            }
        }

        string ans ="/";
        for(auto word:res){
             ans += word;
             ans += "/";
        }
        if(ans.size()>1)  
         ans.pop_back();

         return ans;
    }
};