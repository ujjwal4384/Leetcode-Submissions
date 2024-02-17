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
        if(!root) return NULL;
        if(p->val > q->val) return lowestCommonAncestor(root, q, p);
        if(root->val >= p->val && root->val<=q->val) return root;
        else if(root->val<p->val) return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
    }
};