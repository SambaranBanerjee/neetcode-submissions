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

        right_side = self.lowestCommonAncestor(root.right, p, q)
        left_side = self.lowestCommonAncestor(root.left, p, q)

        if right_side and left_side:
            return root
        elif not right_side and left_side:
            return left_side
        elif right_side and not left_side:
            return right_side
        else:
            return None