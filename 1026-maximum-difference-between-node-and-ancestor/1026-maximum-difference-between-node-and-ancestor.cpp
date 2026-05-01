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
    //return max, min for parent. and also calculate max ans so far.
    pair<int,int> dfs(TreeNode* root, int& ans){
        if(!root) return {INT_MAX, INT_MIN}; //{min, max}
        auto p1 = dfs(root->left, ans);
        auto p2 = dfs(root->right, ans);
        int x = root->val;
        
        int cur_min = min(p1.first, p2.first);
        int cur_max = max(p1.second, p2.second);
        
        if(cur_min == INT_MAX){
            return {x, x};
        }
        ans = max ({ ans, abs(x- cur_min), abs(x- cur_max)  });
        return {min(cur_min, x) ,max(cur_max, x)};
    } 
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};