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
//post order
    //{max_if_skipped, max_if_robbed}
    pair<int,int> dfs(TreeNode* node){
       if(!node) return {0,0}; 
       else if(!node->left && !node->right) return {0, node->val};
       auto leftResult = dfs(node->left); 
       auto rightResult = dfs(node->right); 
       int max_if_robbed =  node->val + leftResult.first + rightResult.first;
       int max_if_skipped =  max({leftResult.first, leftResult.second}) + max({rightResult.first, rightResult.second}) ;
       return {max_if_skipped, max_if_robbed};
    }

    int rob(TreeNode* root) {
        pair<int,int>result =  dfs(root);
        return max({result.first, result.second});
    }
};