class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        if not grid:
            return

        rows , cols = len(grid), len(grid[0])
        q = deque()

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    q.append((r,c))

        directions = [[1,0],[-1,0],[0,1],[0,-1]]
        while q:
            row, col = q.popleft()
            for dr, dc in directions:
                r = row + dr
                c = col + dc
                if 0 <= r < rows and 0 <= c < cols and grid[r][c] == 2147483647:
                    grid[r][c] = grid[row][col] + 1
                    q.append((r,c))
                    