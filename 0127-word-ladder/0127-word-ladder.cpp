class Solution {
public:
    //shortest path=> bfs. 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n= wordList.size();
        set<string> s; 
        for(auto& str: wordList){
            s.insert(str);
        }
        
        queue<string>q;
        q.push(beginWord);
        int ans = 1;
        while(!q.empty()){
             int sz = q.size();
            // cout<<"HI\t"<<sz<<endl;
            while(sz--){
                auto str = q.front();
                
                if(str == endWord) return ans;
                q.pop();
                for(int i=0;i<str.size(); i++){
                    char originalChar = str[i];
                    for(char ch='a'; ch<='z';ch++){
                        
                        if(ch==str[i])continue;
                        else{
                            str[i]=ch;
                            if(s.find(str)!=s.end()){
                                // cout<<str<<"\n";
                                s.erase(str);
                                q.push(str);
                            }
                        }
                    }
                     str[i]= originalChar; 
                    
               }
               
            }
            ans++;
        }
       return 0; 
    }
};