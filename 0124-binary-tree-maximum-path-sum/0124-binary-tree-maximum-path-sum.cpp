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
    int f(TreeNode* root, int& maxi){
        if(!root)return 0;
        int lMax = f(root->left, maxi);
        int rMax = f(root->right, maxi);
        
        int val = root->val;
        maxi = max(maxi, val + lMax + rMax);

        return max(0, max(val + lMax, val + rMax));
    } 
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        f(root, maxi);
        return maxi;
    }
};