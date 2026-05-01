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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q) return p;
        if(!root) return NULL;
        if(root == p || root == q) return root;
       TreeNode* lNode = lowestCommonAncestor(root->left, p, q);
       TreeNode* rNode = lowestCommonAncestor(root->right, p, q);
        
        if(lNode  && rNode ) return root;
        if(!lNode && !rNode) return NULL;
        if(lNode && !rNode) return lNode;
        if(!lNode && rNode) return rNode;
      return NULL;
    }
};