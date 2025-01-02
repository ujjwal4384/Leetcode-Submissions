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
    void f(TreeNode* root, vector<int>&v){
        if(!root) return ;
        f(root->left, v);
        v.push_back(root->val);
        f(root->right, v);
        return ;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        //f(root, v);
        if(!root) return v;

        stack<TreeNode*>st;

        
        TreeNode* cur=root;
        while(cur || !st.empty()){
              if(cur){
                TreeNode* temp=cur;
                while(temp && temp->left){
                    st.push(temp);
                    temp= temp->left;
                }
                v.push_back(temp->val);
                cur= temp->right;
              }else{
                TreeNode* x = st.top();
                st.pop();
                v.push_back(x->val);
                cur = x->right;
              }      
        }
        return v;
    }
};