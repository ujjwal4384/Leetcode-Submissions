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
class BSTIterator {       
private:
 int i;
 vector<int>v;   
public:
    BSTIterator(TreeNode* root) {
        i=0;
        if(!root) return;
        stack<TreeNode*>st;
        TreeNode* cur = root;
        while(!st.empty() || cur){
            if(cur){
                TreeNode* tmp = cur;
                while(tmp){
                    st.push(tmp);
                    tmp=tmp->left;
                }
            }
            cur = st.top();
            v.push_back(cur->val);
            st.pop();
            cur = cur->right;   
        }
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */