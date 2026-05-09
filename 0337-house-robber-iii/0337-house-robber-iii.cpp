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
    vector<vector<int>>dp;
public:
    long long f(TreeNode* node, bool canTake, map<pair<TreeNode*,bool>, long long>&mp){
       if(!node) return 0; 
       else if(mp.count({node, canTake})) return mp[{node,canTake}];
       if(canTake){
        long long a = node->val + f(node->left, !canTake, mp) + f(node->right, !canTake, mp);
        long long b = f(node->left, canTake, mp) + f(node->right, canTake, mp);
        return mp[{node,canTake}] = max({a, b});
       }else{
            return mp[{node,canTake}] = f(node->left, !canTake, mp) + f(node->right, !canTake, mp);
       }
    }

    int rob(TreeNode* root) {
        // dp.assign(50001, vector<int>(2,-1)) ;     
         map<pair<TreeNode*,bool>, long long>mp;
        return (int) f(root, true, mp);
    }
};