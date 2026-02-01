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
    TreeNode* buildHeightBalancedBST(int l, int r, vector<int>&nums){
        if(l>r) return NULL;
        int m = l + ((r-l)>>1) ;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = buildHeightBalancedBST(l, m-1, nums);
        root->right = buildHeightBalancedBST(m+1, r, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildHeightBalancedBST(0, nums.size()-1, nums);
    }
};