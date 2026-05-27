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
    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node) return NULL;
        if(node == p || node == q) return node;
        TreeNode* left = lca(node->left, p, q);
        TreeNode* right = lca(node->right, p, q);
        if(left && right) return node;
        return left ? left : right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(p==q) return p;
        return lca(root, p, q);
    }
};