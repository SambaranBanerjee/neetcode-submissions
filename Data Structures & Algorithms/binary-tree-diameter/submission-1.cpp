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
    int maxDiameter = 0;
    int calculateDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);
        
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);
        return 1 + max(leftDepth,rightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calculateDepth(root);
        return maxDiameter;
    }
};
