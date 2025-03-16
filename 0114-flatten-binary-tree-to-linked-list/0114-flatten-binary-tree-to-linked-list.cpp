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
    void flatten(TreeNode* root) {
        if(!root) return ;
        flatten(root->left);
        flatten(root->right);
        TreeNode* tempLeft = root->left;
        TreeNode* tempRight = root->right;
        root->left = NULL;
        if(tempLeft){
               root->right = tempLeft;
               while(tempLeft->right)tempLeft=tempLeft->right;
               tempLeft->right = tempRight;
               return ;
        }else{
            root->right = tempRight;
            return;
        }
    }
};