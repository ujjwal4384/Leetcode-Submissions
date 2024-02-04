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
    int f(TreeNode*node, int & maxSum){
        if(!node) return 0; 
        
        int lMax= f(node->left, maxSum);
        int rMax = f(node->right, maxSum);
        maxSum = max(maxSum, lMax + rMax + node->val);  
      return max(0,node->val + max(lMax, rMax));      
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int maxSum=INT_MIN;
        f(root, maxSum);
        return maxSum;
    }
};