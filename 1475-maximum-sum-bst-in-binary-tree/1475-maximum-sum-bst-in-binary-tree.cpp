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
struct nodeData{
    int mn = INT_MAX;
    int mx = INT_MIN;
    bool isBST = false;
    int sm = 0;
};

class Solution {
public:
    nodeData f(TreeNode* node, int& ans){
        nodeData nd;

        if(!node){
            nd.isBST = true;
            return nd;
        }
        
        nodeData ndLeft = f(node->left, ans);
        nodeData ndRight = f(node->right, ans);
        if(ndLeft.isBST && ndRight.isBST && node->val > ndLeft.mx && node->val <ndRight.mn){
                nd.isBST = true;
                nd.sm = node->val + ndLeft.sm + ndRight.sm;
                nd.mn = min(ndLeft.mn, node->val); 
                nd.mx = max(ndRight.mx, node->val);
                ans = max(ans, nd.sm);
        }

       return nd;
       
    } 
    int maxSumBST(TreeNode* root) {
       int ans = 0; 
      f(root, ans);

      return ans;
    }
};