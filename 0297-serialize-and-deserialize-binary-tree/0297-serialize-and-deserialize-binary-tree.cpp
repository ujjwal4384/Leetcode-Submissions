/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void serializeHelper(TreeNode* root, ostringstream& out){
        if(!root){
            out<<"N ";
            return;
        }
        out<<(root->val)<<" ";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    TreeNode* deserializeHelper(string& data, istringstream& in){
        string str;
        in>>str;
        if(str == "N"){
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(str));
        TreeNode* left = deserializeHelper(data, in);
        TreeNode* right = deserializeHelper(data, in);
        node->left = left;
        node->right = right;
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(data, in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));