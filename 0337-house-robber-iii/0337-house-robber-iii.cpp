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
    //{max if robbed, max if skipped}
    pair<int,int> dfs(TreeNode* node){
        if(!node) return {0, 0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        int max_if_robbed = node->val + left.second + right.second; 
        int max_if_skipped =  max(left.first, left.second) + max(right.first, right.second);
        return {max_if_robbed, max_if_skipped};
    }
public:
    int rob(TreeNode* root) {
       pair<int,int>res = dfs(root);
       return max(res.first, res.second);
    }
}; 

