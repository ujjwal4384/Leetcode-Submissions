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
    TreeNode* solve(TreeNode* node, int low, int high){
         if(!node) return node;
         TreeNode* left = solve(node->left, low, high);
         TreeNode* right = solve(node->right, low, high);
        
         if(node->val >= low && node->val <=high){
              node->left = left;
              node->right = right;
            return node;   
         }else if(node->val < low){
            return right;
         }else if(node->val > high){
            return left;
         }
         return NULL;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
     return solve(root, low, high);
    }
};