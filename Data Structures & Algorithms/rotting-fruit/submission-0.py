class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        rows, cols = len(grid), len(grid[0])
        q = deque()
        fresh = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    q.append((r,c))
                elif grid[r][c] == 1:
                    fresh += 1
                
        if fresh == 0:
            return 0

        minTime = 0
        directions = [(1,0),(-1,0),(0,1),(0,-1)]
        
        while q and fresh > 0:
            for _ in range(len(q)):
                row, col = q.popleft()
                for dr, dc in directions:
                    r = row + dr
                    c = col + dc
                    if 0 <= r < rows and 0 <= c < cols and grid[r][c] == 1:
                        fresh -= 1
                        q.append((r,c))
                        grid[r][c] = 2
            minTime += 1

        return minTime if fresh == 0 else -1