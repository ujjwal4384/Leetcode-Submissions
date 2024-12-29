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
    int f(TreeNode* node, int&maxSum){
        if(!node) return 0;
        int lMaxSum = f(node->left, maxSum);
        int rMaxSum = f(node->right, maxSum);
        
        int curMax = node->val + lMaxSum + rMaxSum;

        maxSum = max(maxSum, curMax);

        int toReturnSum = max(0, max(node->val+lMaxSum, node->val+rMaxSum));
        
        return toReturnSum;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxSum= root->val;
        f(root, maxSum);
        return maxSum;
    }
};