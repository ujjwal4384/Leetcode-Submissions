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
 //1->2
 */
class Solution {
public:
    int f(TreeNode* node, int&maxi){
        if(!node)return 0;
        int lh=0,rh=0;
        if(node->left) lh = f(node->left, maxi);
        if(node->right) rh = f(node->right, maxi);
         maxi= max(maxi,  lh+rh);
        return 1+ max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        f(root, maxi);
        return maxi;
    }
};