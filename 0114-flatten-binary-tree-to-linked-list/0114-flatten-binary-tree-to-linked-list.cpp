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
        
        TreeNode* curRoot = root;
        TreeNode* curLeft = root->left;
        TreeNode* curRight = root->right;
        curRoot->left = NULL;
        curRoot->right = NULL;

        if(curLeft==NULL){
            curRoot->right = curRight;
            return;
        }
        
        TreeNode* temp = curLeft;
        while(temp->right){
            temp = temp->right;
        }

        temp->right = curRight;

        curRoot->right = curLeft;

        return ;
    }
};