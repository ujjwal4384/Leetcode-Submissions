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
        if(!root) return {-1e6, -1e6};
        auto p1 = dfs(root->left, ans);
        auto p2 = dfs(root->right, ans);
        int x = root->val;
        set<int>s;
        if(p1.first != -1e6)s.insert(p1.first);
        if(p1.second != -1e6)s.insert(p1.second);
        if(p2.first != -1e6)s.insert(p2.first);
        if(p2.second != -1e6)s.insert(p2.second);
        if(s.empty()){
            return {x, x};
        }
        
        int mini = *s.begin();
        int maxi = *(--s.end());
        ans = max ({ ans, abs(x- mini), abs(x- maxi)  });
        return {min(mini, x) ,max(maxi, x)};
    } 
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};