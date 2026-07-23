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

class Codec {
private:
    void serializeDFS(TreeNode* root, stringstream& ss) {
        if (root == nullptr) {
            ss << "N,";
            return;
        }
        ss << root->val << ",";
        serializeDFS(root->left, ss);
        serializeDFS(root->right, ss);
    }

    TreeNode* deserializeDFS(stringstream& ss) {
        string token;
        if (!getline(ss, token, ',')) {
            return nullptr;
        }

        if (token == "N") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeDFS(ss);
        node->right = deserializeDFS(ss);

        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serializeDFS(root,ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeDFS(ss);
    }
};
