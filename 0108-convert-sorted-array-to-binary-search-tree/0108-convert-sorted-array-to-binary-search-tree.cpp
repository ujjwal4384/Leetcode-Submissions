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
    TreeNode* f1(int l, int r, vector<int>& nums){
       if(l>r) return NULL;
       int m = (l+r)/2 ;
       int key = nums[m];
       TreeNode* node = new TreeNode(key);
       
       node->left = f1(l, m-1, nums);
       node->right = f1(m+1, r, nums);

       return node;
    }
    TreeNode* f(int& i, vector<int>& nums, int count){
        if(count==0) return NULL;
        TreeNode* left = f(i, nums, count/2);

        TreeNode* node = new TreeNode(nums[i]);
        node->left = left;
        i++;
        node->right = f(i, nums, count - count/2 -1);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
       //return f1(0, nums.size()-1, nums);
       int i =0;
       return f(i, nums, nums.size());
    }
};