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
    void f(TreeNode* root, vector<string>&v, string s){
        if(!root){
            return;
        }
        int val = root->val;
        string val_str = to_string(val);
        string s_new = s + val_str;
        if(!root->left && !root->right){
            v.push_back(s_new);    
            return ;
        }
        
        f(root->left, v, s_new);
        f(root->right, v, s_new);
    } 

    int getNumberFromString(string& s){
        return stoi(s);
    }

    int sumNumbers(TreeNode* root) {
        vector<string>v;
        string s="";
        f(root, v, s);
        int sum = 0;
        for(auto x:v){
                int num = getNumberFromString(x);
                sum += num;
        }
        return sum;
    }
};