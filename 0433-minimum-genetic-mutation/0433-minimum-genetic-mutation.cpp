class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene) return 0;
        
        int n = startGene.size(); 
        unordered_set<string>valid;
        for(auto s:bank){
            valid.insert(s);
        }

        if(valid.find(endGene) == valid.end()) return -1;
        int bankSize = valid.size();

        unordered_map<string,bool>vis;
        queue<string>q;
        vis[startGene] = true;
        q.push(startGene);

        int steps = 0;

        while(!q.empty() && steps<=bankSize){
            int sz = q.size();
            while(sz--){
                string str = q.front();
                q.pop();
                if(str == endGene) return steps;
                for(int pos = 0; pos<n; pos++){
                    char val = str[pos];
                    for(char ch='A';ch<='Z';ch++){
                        if(ch == val) continue;
                        str[pos] = ch;
                        if(!vis[str]  && valid.find(str) != valid.end()){
                            vis[str] = true;
                            q.push(str); 
                        }
                    }
                    str[pos] = val;
                }   
            }
            steps++;
        } 

        return -1;
    }
};