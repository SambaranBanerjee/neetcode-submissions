# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root:
            return None
        
        if root == p or root == q:
            return root
        
        left_side = self.lowestCommonAncestor(root.left, p, q)
        right_side = self.lowestCommonAncestor(root.right, p, q)

        if not left_side and not right_side:
            return None
        
        if not left_side:
            return right_side
        elif not right_side:
            return left_side
        else:
            return root