class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(endGene == startGene) return 0;
        if(find(bank.begin(), bank.end(), endGene) == bank.end()) return -1;

        bank.push_back(startGene);
        reverse(bank.begin(),bank.end());
        
        int n = bank.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n; j++){
                string s1 = bank[i],  s2= bank[j];
                int dif =0;
                for(int k=0;k<s1.size();k++){
                    if(s1[k] != s2[k])dif++;
                }
                if(dif==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int>q;
        vector<bool>vis(n, false);
        vis[0] = true;
        q.push(0);

        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                 int node = q.front();
                  q.pop();
                  for(auto&nb:adj[node]){
                       if(!vis[nb]){
                         if(bank[nb] == endGene) return steps + 1;
                         vis[nb] = true;
                         q.push(nb);
                       }
                  }
            }
            if(q.size())steps++;
        }
        return -1;
    }
};