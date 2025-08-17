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
    TreeNode* buildTree(vector<int>&post, vector<int>&in, int pl, int pr, int il, int ir){
        if(pl>pr || il > ir) return NULL;
        int inId = -1;
        for(int k=il;k<=ir;k++){
               if(in[k] == post[pr]){
                  inId = k;
                  break;
               } 
        }

        int cnt_left = inId - il;
        int cnt_right = ir - inId;
        TreeNode* node = new TreeNode(post[pr]);

        node->left = buildTree(post, in, pl, pr-cnt_right-1, il, il+cnt_left-1);
        node->right = buildTree(post, in, pr-cnt_right, pr-1,il+cnt_left+1 ,ir);

        return node;
    }    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size() ;

       return buildTree(postorder, inorder, 0, n-1, 0, n-1); 
    }
};