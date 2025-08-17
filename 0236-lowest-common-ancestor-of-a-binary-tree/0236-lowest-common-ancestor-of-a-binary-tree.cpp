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
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if(root ==p || root ==q) return root;

        TreeNode* lt = f(root->left, p, q);
        TreeNode* rt = f(root->right, p, q);
        if(lt&&rt) return root;
        else if(lt) return lt;
        else if(rt) return rt;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(p==q) return p;
        return f(root, p, q);
    }
};