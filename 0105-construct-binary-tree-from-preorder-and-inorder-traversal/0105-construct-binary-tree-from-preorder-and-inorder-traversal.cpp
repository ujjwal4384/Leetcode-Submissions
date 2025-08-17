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
private:
    TreeNode* buildTree(vector<int>&pre, vector<int>&in, int pl, int pr, int il, int ir){
        if(pl>pr || il > ir) return NULL;
        int inId = -1;
        for(int k=il;k<=ir;k++){
               if(in[k] == pre[pl]){
                  inId = k;
                  break;
               } 
        }

        int cnt_left = inId - il;
        TreeNode* node = new TreeNode(pre[pl]);

        node->left = buildTree(pre, in, pl+1, pl+cnt_left, il, il+cnt_left-1);
        node->right = buildTree(pre, in, pl+cnt_left+1, pr,il+cnt_left+1 ,ir);

        return node;
    }    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int n = preorder.size() ;

       return buildTree(preorder, inorder, 0, n-1, 0, n-1); 
    }
};