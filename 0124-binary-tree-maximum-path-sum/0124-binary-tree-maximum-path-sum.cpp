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
        int a= val + lMax;
        int b= val + rMax;
        int c= val + lMax + rMax;
        
        int d = max(val, max(a,max(b,c)));

        maxi = max(maxi, d);

        return max(val, max(a, b));
    } 
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        f(root, maxi);
        return maxi;
    }
};