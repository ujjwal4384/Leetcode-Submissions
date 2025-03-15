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
    TreeNode* buildBST(int &i, vector<int>& preorder, int mini, int maxi){
        if(i== preorder.size()) return NULL;
        int key = preorder[i];
        if(key<= mini || key >=maxi) return NULL;

        TreeNode* node = new TreeNode(key);

        i++;
        if(i< preorder.size()){
            node->left = buildBST(i, preorder, mini, key);
        }
        if(i< preorder.size()){
            node->right = buildBST(i, preorder, key, maxi);
        }
        return node;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0;
        return buildBST(i, preorder, INT_MIN, INT_MAX);
    }
};