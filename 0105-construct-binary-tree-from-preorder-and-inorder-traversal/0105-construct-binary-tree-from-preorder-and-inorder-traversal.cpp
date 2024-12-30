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
    TreeNode* f(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl>pr || il>ir) return NULL;
        int nodeId = -1;
        //find this node in inorder->
        for(int i=il;i<=ir; i++){
            if(inorder[i] == preorder[pl]){
                nodeId=i;
                break;
            }
        }
        int cnt_left = nodeId - il;
        TreeNode* node = new TreeNode(preorder[pl]);
        node->left = f(preorder, inorder, pl+1, pl+cnt_left, il, nodeId-1 ); 
        node->right =f(preorder, inorder, pl+cnt_left+1, pr, nodeId+1, ir);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return f(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};