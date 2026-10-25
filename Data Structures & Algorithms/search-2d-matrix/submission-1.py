class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix and not matrix[0]:
            return False

        row = len(matrix)
        col = len(matrix[0])

        left = 0
        right = (row * col) - 1

        while (left <= right):
            mid = (left + right) // 2

            row_idx = mid // col
            col_idx = mid % col
            mid_val = matrix[row_idx][col_idx]
            
            if mid_val == target:
                return True
            elif mid_val < target:
                left = mid + 1
            else:
                right = mid - 1

        return False