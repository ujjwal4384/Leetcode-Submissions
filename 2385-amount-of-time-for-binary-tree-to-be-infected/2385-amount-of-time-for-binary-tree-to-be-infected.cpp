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
    int dfs(TreeNode* root, int& start, int& maxTime){
        if(!root) return 0;
        int left = dfs(root->left, start, maxTime);
        int right = dfs(root->right, start, maxTime);

        if(root->val == start){
            //inform parent i am startNode ans distance from me is 1.
            maxTime = max(left, right);
            return -1;
        }

        else if(left>=0 && right >=0){
            //both returned height => startNode is not in this subtree.
            //just return height of the subtree
            return max(left,right) +1;
        }

        else if(left <0){
        //implies startNode is in leftSubtree and is at distance abs(left) from the node.
        //so max time taken to burn right part of subtree = dist(left) + height of right part.
          maxTime = max(maxTime, abs(left) + right);
          return left -1; //increment the distance for his parent.
        }
        else if(right <0){
          maxTime = max(maxTime, abs(right) + left); 
          return right -1; //increment the distance for his parent.
        }
        return -1; //not possible case
    }

    int amountOfTime(TreeNode* root, int start) {
       int maxTime = 0;
       dfs(root, start, maxTime);//it either return sheight of the node or distance of the node from startNode.
       return maxTime ; 
    }
};