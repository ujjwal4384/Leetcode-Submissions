class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>visited(deadends.begin(), deadends.end());
        if(visited.count(target) || visited.count("0000")) return -1;
        if(target == "0000") return 0;

        queue<string>q;
        q.push("0000");

        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                    string node = q.front();
                    q.pop() ;
                    for(int i=0;i<4;i++){
                        char ch = node[i];
                        char up_ch = (ch=='9'? '0' : ch + 1);
                        char down_ch = (ch=='0'? '9' : ch - 1);
                        string nb1 = node, nb2 = node;
                        nb1[i] = up_ch, nb2[i] = down_ch;
                        if(target == nb1 || target == nb2) return steps+1;
                        if(!visited.count(nb1)){
                            visited.insert(nb1);
                            q.push(nb1);
                        }    
                        if(!visited.count(nb2)){
                            visited.insert(nb2);
                            q.push(nb2);
                        }    
                    }
            }
            if(q.size())steps++;
        }
        return -1;
    }
};