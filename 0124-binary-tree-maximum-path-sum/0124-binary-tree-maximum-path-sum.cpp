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
    long long f(TreeNode*node, long long& ans){
        if(!node) return INT_MIN;
        long long leftAns = f(node->left, ans);
        long long rightAns = f(node->right, ans);
        long long cur = max({0LL + node->val, node->val + leftAns, node->val + rightAns, node->val+leftAns + rightAns});
        ans = max(ans, cur);
        return max({0LL + node->val, node->val + leftAns, node->val + rightAns});
    }
    int maxPathSum(TreeNode* root) {
        long long ans = INT_MIN;
        f(root, ans);
        return (int)ans;
    }
};