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
    int f(TreeNode* node, int& maxi){
        if(!node) return 0;
        int lMax = f(node->left, maxi);
        int rMax = f(node->right, maxi); 
        maxi = max(maxi, lMax+rMax+1);

        return 1 + max(lMax, rMax);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxi=INT_MIN;
        f(root, maxi);
        return maxi-1;
    }
};