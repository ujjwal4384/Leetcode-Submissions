/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q, vector<bool>&found){
         if(!root) return NULL;
        //for PART 2 : where nodes might be absent. 
        
        TreeNode* lNode = dfs(root->left, p, q, found);
        TreeNode* rNode = dfs(root->right, p, q, found);
        if(root == p){
             found[0] = true;
             return root;
        }
        else if(root == q){
             found[1] = true;
             return root;
        }

        if(lNode  && rNode) return root;
        return lNode ? lNode : rNode;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q) return p;
        if(!root) return NULL;
        //for PART 2 : where nodes might be absent. 
        vector<bool>found(2, false);
       TreeNode* lca = dfs(root, p, q, found);
      return found[0] && found[1] ? lca : NULL;
    }
};