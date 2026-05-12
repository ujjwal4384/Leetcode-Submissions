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
    private:
    void serializeHelper(TreeNode* root, ostringstream& out){
        if(!root){
            out<<"N"<<" ";
            return;
        }

        out<<root->val<<" ";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    };

    TreeNode* deserializeHelper(istringstream& in){
        string val;
        getline(in, val, ' '); //or in>>val; default is space delimiter
        if(val == "N"){
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        cout<< out.str()<< endl;
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));