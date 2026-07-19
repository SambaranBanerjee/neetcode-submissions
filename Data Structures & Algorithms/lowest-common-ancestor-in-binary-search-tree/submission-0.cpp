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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }
        
        TreeNode* rightSearch = lowestCommonAncestor(root->right, p, q);
        TreeNode* leftSearch = lowestCommonAncestor(root->left, p, q);

        if (rightSearch != nullptr && leftSearch != nullptr) {
            return root;    
        }
        else if (rightSearch == nullptr && leftSearch != nullptr) {
            return leftSearch;
        }
        else if (rightSearch != nullptr && leftSearch == nullptr) {
            return rightSearch;
        }
        else {
            return nullptr;
        }
    }
};
