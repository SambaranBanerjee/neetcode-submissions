class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])

        maxArea = 0
        visited = set()

        def bfs(r,c):
            q = deque()
            q.append((r,c))
            visited.add((r,c))
            area = 1

            while q:
                row, col = q.pop()
                directions = [[1,0],[-1,0],[0,1],[0,-1]]
                for dr, dc in directions:
                    r = row + dr
                    c = col + dc
                    if (r in range(rows) and c in range(cols) and 
                        (grid[r][c] == 1) and(r,c) not in visited):
                            area += 1
                            q.append((r,c))
                            visited.add((r,c))
            
            return area


        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1 and (r,c) not in visited:
                    area = bfs(r,c)
                    maxArea = max(maxArea,area)

        return maxArea