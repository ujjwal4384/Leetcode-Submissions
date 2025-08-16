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
    int f(TreeNode* node, int h){
        if(!node) return h;
        return max(f(node->left, h+1), f(node->right, h+1)); 
    }
    int maxDepth(TreeNode* root) {
        return f(root, 0);
    }
};