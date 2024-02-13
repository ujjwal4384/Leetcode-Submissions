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
    TreeNode* f(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r, unordered_map<int,int>&mp){
        if(pre_l> pre_r || in_l > in_r) return NULL;
        
        TreeNode* node = new TreeNode(preorder[pre_l]);
        
        //find node's index in inorder
        int node_id = mp[preorder[pre_l]];
        int cnt_left = node_id- in_l;
        //now make node->left and right subtree
        node->left = f(preorder, inorder, pre_l+1, pre_l+cnt_left, in_l, node_id-1, mp);
        node->right = f(preorder, inorder, pre_l+cnt_left+1, pre_r, node_id+1, in_r, mp);
        
     return node;   
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        for(int i=0;i<inorder.size(); i++)mp[inorder[i]] = i;
        return f(preorder, inorder,0, preorder.size() -1, 0, inorder.size()-1, mp);
    }
};