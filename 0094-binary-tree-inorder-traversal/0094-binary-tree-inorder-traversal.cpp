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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* cur = root;
        vector<int>v;
        while(cur || !st.empty()){
                if(cur){
                    TreeNode* tmp = cur;
                    while(tmp->left){
                        st.push(tmp);
                        tmp = tmp->left;
                    }
                    v.push_back(tmp->val); 
                    cur = tmp->right;
                }else{
                    TreeNode* tmp = st.top();
                    st.pop();
                    v.push_back(tmp->val);
                    cur = tmp->right;
                }
        }
      return v;
    }
};