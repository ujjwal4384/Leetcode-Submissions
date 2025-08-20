/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, map<Node*,Node*>&mp, int& cnt){
        if(!node){
             mp[node] = NULL; 
             return;
        }

        cnt++;
        mp[node] = new Node(node->val);
        for(auto adjNode:node->neighbors){
             if(mp.find(adjNode) == mp.end()){
                dfs(adjNode, mp, cnt);
             }
        }
    }

    void dfsReturns(Node* node, map<Node*,Node*>&mp, bool vis[]){
        if(!node) return ;
        vis[node->val] = true;
        
        for(auto adjNode:node->neighbors){
             mp[node]->neighbors.push_back(mp[adjNode]);
        }

        for(auto adjNode:node->neighbors){
             if(!vis[adjNode->val]){
                dfsReturns(adjNode, mp, vis);
             }
        }
    }

    Node* cloneGraph(Node* node) {
        map<Node*,Node*>mp;
        int cnt =0;
        dfs(node, mp, cnt);
        bool* vis = new bool[cnt+1]{false};
        dfsReturns(node, mp, vis);

       return mp[node]; 
    }
};