/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* node, TreeNode*target, vector<TreeNode*>&path){
        if(!node)return 0;
        if(node==target){
            path.push_back(node);
            return 1;
        }
        
        bool f1 = getPath(node->left, target, path);
        bool f2 = getPath(node->right, target, path);
        if(f1 || f2)path.push_back(node);
        return f1 || f2;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==q) return p;
        vector<TreeNode*>pathP,pathQ;
        getPath(root, p, pathP);
        getPath(root, q, pathQ);
        reverse(pathP.begin(),pathP.end());
        reverse(pathQ.begin(),pathQ.end());
        int i=0;
        while(i<min(pathP.size(), pathQ.size()) && pathP[i]==pathQ[i])i++;
        
        i--;
        
        return pathP[i];
    }
    
};