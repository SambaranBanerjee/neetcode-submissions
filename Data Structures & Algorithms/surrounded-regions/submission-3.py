class Solution:
    def solve(self, board: List[List[str]]) -> None:
        if not board or not board[0]:
            return
        rows, cols = len(board), len(board[0])
        q = deque()

        for r in range(rows):
            for c in range(cols):
                if (r == 0 or r == rows - 1 or c == 0 or c == cols - 1) and board[r][c] == "O":
                    q.append((r,c))
                    board[r][c] = "T"

        directions = [(1,0),(-1,0),(0,1),(0,-1)]
        while q:
            row, col = q.popleft()
            for dr,dc in directions:
                r = row + dr
                c = col + dc
                if (0 <= r < rows and 0 <= c < cols and board[r][c] == "O"):
                    board[r][c] = "T"
                    q.append((r,c))

        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "O":
                    board[r][c] = "X"
                elif board[r][c] == "T":
                    board[r][c] = "O"
        
        
            



