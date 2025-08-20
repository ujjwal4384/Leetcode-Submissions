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
    Node* dfs(Node* node, map<Node*,Node*>&mp){
        if(!node)return NULL;
        if(mp.find(node) == mp.end()){
            mp[node] = new Node(node->val);
            for(auto adjNode:node->neighbors){ 
                Node* nb = dfs(adjNode, mp);
                mp[node]->neighbors.push_back(nb);     
            }
        }

        return mp[node];
    }

    
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>mp;
       
        return dfs(node, mp);
        
    }
};