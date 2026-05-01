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
    //return max, min for parent. and also calculate max ans so far.
    int solve(TreeNode* root, int cur_min, int cur_max){
        if(!root) return cur_max - cur_min;

        int x = root->val;
         cur_min = min(cur_min, x);
         cur_max = max(cur_max, x);
        int left_dif = solve(root->left, cur_min, cur_max);
        int right_dif = solve(root->right, cur_min, cur_max);
        
        return max(left_dif, right_dif);
        } 
    
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }
};