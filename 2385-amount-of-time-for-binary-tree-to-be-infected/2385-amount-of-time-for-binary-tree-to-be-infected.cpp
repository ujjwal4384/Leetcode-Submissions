/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*>parMap;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* startNode;
        while(!q.empty()){
            TreeNode* top = q.front(); q.pop();
            if(top->val == start){
                startNode = top;
            }
            if(top->left){
                parMap[top->left] = top;
                q.push(top->left);
            }
            if(top->right){
                parMap[top->right] = top;
                q.push(top->right);
            }
        }

        q.push(startNode);
        unordered_map<TreeNode*, bool>vis;
        vis[startNode] = true;
        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                    TreeNode* top = q.front(); q.pop(); 
                    if(top->left && !vis.count(top->left)){
                        
                        q.push(top->left);
                        vis[top->left] = true;
                    }
                    if(top->right && !vis.count(top->right)){
                        
                        q.push(top->right);
                        vis[top->right] = true;
                    }

                    if(parMap.count(top) && !vis.count(parMap[top])){
                        q.push(parMap[top]);
                        vis[parMap[top]] = true;
                    }
            }
            if(q.size())time++;
        }
        return time;
    }
};