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
    }
    
    vector<int> stackFunc(TreeNode* root){
           vector<int>v;
       
        stack<TreeNode*>st;
       
        TreeNode* cur=root;
        while(cur || !st.empty()){
           while(cur){
               st.push(cur);
               cur=cur->left;
           }
            TreeNode* node = st.top();              
            v.push_back(node->val);
            st.pop();
            cur=node->right;
          
        }
        return v;
    }
    void morrisInorder(TreeNode* root, vector<int>&inorder){
        TreeNode* cur=root;
        while(cur){
//case 1: no left subtree: just pick the node and move right;
            if(!cur->left){
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            
            else{
                TreeNode* prev = cur->left;
                TreeNode* temp = prev;      
                while(temp->right && temp->right != cur){
                    temp=temp->right;
                }
//case2: rightmost node of left subtree points to null. connect it to cur node.
                if(!temp->right){
                    temp->right = cur;
                    cur= cur->left;
                }
 //case3: rightmost node of left subtree already pointing to curren node=> break the links, pick this node and move right.                 
                else {
                    temp->right = NULL;
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
         
    }
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int>inorder;
        //morris
        morrisInorder(root, inorder);
        return inorder;
    }
};