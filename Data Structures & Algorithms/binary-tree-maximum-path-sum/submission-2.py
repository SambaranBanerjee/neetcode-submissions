# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum = float('-inf')
        def dfs(root: Optional[TreeNode]) -> int:
            if not root:
                return 0
            
            nonlocal maxSum

            left_sum = max(dfs(root.left), 0)
            right_sum = max(dfs(root.right), 0)

            both_path_correct_sum = left_sum + right_sum + root.val
            one_path_correct_sum = max(left_sum, right_sum) + root.val

            maxSum = max(maxSum, both_path_correct_sum, one_path_correct_sum)

            return one_path_correct_sum
        dfs(root)
        return maxSum